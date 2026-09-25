# ctrl-a

Select-all for Kali’s default terminal.

[![release](https://img.shields.io/github/v/release/iinze0/ctrl-a?style=flat-square)](https://github.com/iinze0/ctrl-a/releases/latest)
[![license](https://img.shields.io/badge/license-MIT-0b7285?style=flat-square)](LICENSE)
[![arch](https://img.shields.io/badge/arch-amd64-555?style=flat-square)](#install)

Made by [iinze0](https://github.com/iinze0)

Kali’s QTerminal has no Select All. This package turns **Ctrl+A** on in the terminal you already open — QTerminal, plus xfce4-terminal, gnome-terminal, and Konsole. It is not a second app.

| Key | Action |
|:----|:-------|
| **Ctrl+A** | Select the whole scrollback and copy it |
| **Home** | Jump to the start of the line |

Close every terminal after installing, then open Terminal again.

## Install

```bash
wget -O /tmp/ctrl-a.deb https://github.com/iinze0/ctrl-a/releases/download/v1.1.0/ctrl-a_1.1.0_amd64.deb
sudo dpkg -i /tmp/ctrl-a.deb
```

One-liner:

```bash
curl -fsSL https://raw.githubusercontent.com/iinze0/ctrl-a/main/install-ctrl-a.sh | sudo bash
```

```bash
sudo apt purge ctrl-a    # uninstall
```

## Notes

- Architecture: `amd64`
- Reopen the terminal after install so the binding is picked up

---

<p align="center">
  <a href="https://github.com/iinze0">iinze0</a> ·
  <a href="LICENSE">MIT</a>
</p>
