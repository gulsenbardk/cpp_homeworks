#!/usr/bin/env bash 

mkdir build 
c++ -c  -I../include src/sum.cpp -o build/sum.o
c++ -c  -I../include src/subtract.cpp -o build/subtract.o
ar rcs build/libipb_arithmetic.a build/subtract.o build/sum.o

mkdir -p results/bin
mkdir -p results/lib
cp build/libipb_arithmetic.a results/lib

c++ -std=c++17 -c -I include/ src/main.cpp -o build/main.o
c++ -std=c++17 ../build/main.o -L . -lipb_arithmetic -o main