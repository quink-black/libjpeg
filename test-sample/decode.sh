#!/bin/bash

bin=../build/jpeg-xt
num=20

time ./hdr-decoder.sh $bin $num
time ./ldr-decoder.sh $bin $num
