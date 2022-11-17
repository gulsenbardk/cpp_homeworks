#!/usr/bin/env bash
wc -l < data.dat
grep -c -e "d*lor" data.dat
wc -w < data.dat
grep -c '\<mol' data.dat