#!/usr/bin/env bash 

mkdir -p build 
c++ -c  -I./include/ src/subtract.cpp -o build/subtract.o
c++ -c  -I./include/ src/sum.cpp -o build/sum.o
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o


mkdir -p results/bin
mkdir -p results/lib
cp build/libipb_arithmetic.a ./results/lib

