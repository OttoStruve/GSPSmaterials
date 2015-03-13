#!/bin/bash

## Compile ##
gcc pi_serial.c -lm -o pi_serial

## Execute ##
time ./pi_serial