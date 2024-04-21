#!/bin/bash

curl -OL https://github.com/exercism/cli/releases/download/v3.3.0/exercism-3.3.0-linux-x86_64.tar.gz
mkdir exercism
tar -xf exercism-3.3.0-linux-x86_64.tar.gz -C exercism
mv exercism/exercism ~/.local/bin
chmod +x ~/.local/bin/exercism
rm exercism-3.3.0-linux-x86_64.tar.gz
rm -rf exercism

~/.local/bin/exercism configure -w ~/projects/exercism