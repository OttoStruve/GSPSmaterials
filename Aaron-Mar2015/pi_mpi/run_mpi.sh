#!/bin/bash

## Compile ##
mpicc pi_mpi.c -lm -o pi_mpi

## Execute ##
time mpiexec -n 4 ./pi_mpi