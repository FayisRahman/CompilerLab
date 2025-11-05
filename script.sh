#!/bin/bash


./sol.out $1

cd label_translation
./label.sh
cd ..
./xsm -l library.lib -e machinecode.xsm