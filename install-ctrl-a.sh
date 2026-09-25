#!/bin/bash
set -euo pipefail
sudo apt-get update
sudo apt-get install -y python3 python3-gi gir1.2-gtk-3.0 gir1.2-vte-2.91
wget -O /tmp/ctrl-a.deb https://github.com/iinze0/ctrl-a/releases/download/v1.0.0/ctrl-a_1.0.0_all.deb
sudo dpkg -i /tmp/ctrl-a.deb
echo "Installed. Open it with: ctrl-a"
