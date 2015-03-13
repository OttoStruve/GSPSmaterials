#!/bin/bash

## Compile ##
export OMP_NUM_THREADS=4 # threads/task
/usr/local/bin/gcc -fopenmp pi_openmp.c -lm -o pi_openmp

## Execute ##
time ./pi_openmp