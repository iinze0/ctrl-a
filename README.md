# ctrl-a

**Made by iinze0**

Ctrl+A in the **normal** Kali terminal. Not a second app.

Kali's terminal has no Select All. After this, **Ctrl+A** selects the whole scrollback and copies it. **Home** still jumps to the start of the line.

Close every terminal window after installing, then open Terminal again.

## Install

```bash
wget -O /tmp/ctrl-a.deb https://github.com/iinze0/ctrl-a/releases/download/v1.1.0/ctrl-a_1.1.0_amd64.deb
sudo dpkg -i /tmp/ctrl-a.deb
```

Then close the terminal and open it again. Press **Ctrl+A**.

Uninstall: `sudo apt purge ctrl-a`
