#!/usr/bin/env bash 

mkdir build 
c++ -c  -I./include/ src/subtract.cpp -o build/subtract.o
c++ -c  -I./include/ src/sum.cpp -o build/sum.o
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
cp build/libipb_arithmetic.a ./results/lib

mkdir -p results/bin
mkdir -p results/lib

c++ -std=c++17 -c -I include/ src/main.cpp -o build/main.o
c++ -std=c++17 build/main.o -L results/lib/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic