/* Hooks Ctrl+A inside the normal QTerminal and selects the whole buffer. */
#include <QApplication>
#include <QCoreApplication>
#include <QEvent>
#include <QKeyEvent>
#include <QMetaObject>
#include <QWidget>

#include <dlfcn.h>
#include <pthread.h>
#include <unistd.h>

using SetFn = void (*)(void *, int, int);
using CountFn = int (*)(void *);

static SetFn set_start;
static SetFn set_end;
static CountFn hist_lines;
static CountFn screen_rows;
static CountFn screen_cols;

static void resolve()
{
    set_start = (SetFn)dlsym(RTLD_DEFAULT, "_ZN11QTermWidget17setSelectionStartEii");
    set_end = (SetFn)dlsym(RTLD_DEFAULT, "_ZN11QTermWidget15setSelectionEndEii");
    hist_lines = (CountFn)dlsym(RTLD_DEFAULT, "_ZN11QTermWidget17historyLinesCountEv");
    screen_rows = (CountFn)dlsym(RTLD_DEFAULT, "_ZN11QTermWidget16screenLinesCountEv");
    screen_cols = (CountFn)dlsym(RTLD_DEFAULT, "_ZN11QTermWidget18screenColumnsCountEv");
}

static bool is_text_field(QWidget *w)
{
    return w->inherits("QLineEdit") || w->inherits("QTextEdit") || w->inherits("QPlainTextEdit") || w->inherits("QComboBox");
}

class Filter : public QObject
{
public:
    explicit Filter(QObject *parent) : QObject(parent) {}

    bool eventFilter(QObject *, QEvent *event) override
    {
        if (event->type() != QEvent::KeyPress)
            return false;
        auto *key = static_cast<QKeyEvent *>(event);
        if (key->key() != Qt::Key_A || key->isAutoRepeat())
            return false;
        const Qt::KeyboardModifiers mods = key->modifiers();
        if (!(mods & Qt::ControlModifier))
            return false;
        if (mods & (Qt::ShiftModifier | Qt::AltModifier | Qt::MetaModifier))
            return false;

        QWidget *focus = QApplication::focusWidget();
        if (!focus || is_text_field(focus))
            return false;

        for (QWidget *p = focus; p; p = p->parentWidget()) {
            if (!p->inherits("QTermWidget"))
                continue;
            if (!set_start)
                resolve();
            if (!set_start || !set_end || !hist_lines || !screen_rows || !screen_cols)
                return false;
            const int rows = screen_rows(p);
            const int cols = screen_cols(p);
            if (rows < 1 || cols < 1)
                return false;
            int last = hist_lines(p) + rows - 1;
            if (last < 0)
                last = 0;
            set_start(p, 0, 0);
            set_end(p, last, cols - 1);
            QMetaObject::invokeMethod(p, "copyClipboard");
            p->update();
            focus->update();
            return true;
        }
        return false;
    }
};

static void install()
{
    static bool done = false;
    if (done || !qApp)
        return;
    done = true;
    qApp->installEventFilter(new Filter(qApp));
}

static void *waiter(void *)
{
    for (int i = 0; i < 400; ++i) {
        if (QCoreApplication::instance()) {
            QMetaObject::invokeMethod(QCoreApplication::instance(), []() { install(); }, Qt::QueuedConnection);
            return nullptr;
        }
        usleep(50 * 1000);
    }
    return nullptr;
}

__attribute__((constructor)) static void ctrl_a_init()
{
    pthread_t thread;
    if (pthread_create(&thread, nullptr, waiter, nullptr) == 0)
        pthread_detach(thread);
}
