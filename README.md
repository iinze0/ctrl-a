<div align="center">

<img src="banner.png" width="720" alt="ctrl-a" />

**select all in the normal kali terminal**

```diff
+ made by iinze0
+ not a second app
```

</div>

---

Kali's terminal has no Select All. This turns **Ctrl+A** on in the one you already open.

| key | what it does |
|:----|:-------------|
| **Ctrl+A** | select the whole scrollback and copy it |
| **Home** | jump to the start of the line |

Close every terminal after installing, then open Terminal again.

## Install

```bash
wget -O /tmp/ctrl-a.deb https://github.com/iinze0/ctrl-a/releases/download/v1.1.0/ctrl-a_1.1.0_amd64.deb
sudo dpkg -i /tmp/ctrl-a.deb
```

Uninstall: `sudo apt purge ctrl-a`

```
github.com/iinze0
github.com/iinze0/ctrl-a
```
