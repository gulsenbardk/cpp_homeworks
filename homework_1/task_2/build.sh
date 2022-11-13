#!/usr/bin/env bash 

mkdir build 
cd build
c++ -c  -I../include ../src/main.cpp -o main.o
c++ -c  -I../include ../src/subtract.cpp -o subtract.o
c++ -c  -I../include ../src/sum.cpp -o sum.o
ar rcs libipb_arithmetic.a sum.o subtract.o
cd ..
cp libipb_arithmetic.a results/lib

c++ -std=c++17 -c -I include/ src/main.cpp -o build/main.o
c++ -std=c++17 build/main.o -L build/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic