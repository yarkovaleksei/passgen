#!/bin/bash

make clean
make
sudo make build install=yes
make autodoc
make clean
make distclean
git add --all
git commit -a
git push origin master
