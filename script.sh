#!/bin/bash

cd TreeViz
make clean

cd ..

./sol.out $1 $2

cd label_translation
./label.sh
cd ..
./xsm -l library.lib -e machinecode.xsm $2