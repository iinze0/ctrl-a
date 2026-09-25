#!/bin/bash
set -euo pipefail
wget -O /tmp/ctrl-a.deb https://github.com/iinze0/ctrl-a/releases/download/v1.1.0/ctrl-a_1.1.0_amd64.deb
sudo dpkg -i /tmp/ctrl-a.deb
echo "Installed. Close every terminal, open Terminal again, then press Ctrl+A."
