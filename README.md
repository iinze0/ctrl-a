# ctrl-a

**Made by iinze0**

Kali's terminal (QTerminal) has no Select All. This one does.

**Ctrl+A** selects the whole scrollback and copies it.
**Alt+A** moves to the start of the line (what Ctrl+A used to do).

Your normal terminal is left alone. Open this one when you want the text.

## Install

```bash
wget -O /tmp/ctrl-a.deb https://github.com/iinze0/ctrl-a/releases/download/v1.0.0/ctrl-a_1.0.0_all.deb
sudo apt-get install -y python3 python3-gi gir1.2-gtk-3.0 gir1.2-vte-2.91
sudo dpkg -i /tmp/ctrl-a.deb
ctrl-a
```

Or from the app menu: **Ctrl+A**.

Copy after that is already done. Paste somewhere else with **Ctrl+Shift+V**.

Uninstall: `sudo apt purge ctrl-a`
