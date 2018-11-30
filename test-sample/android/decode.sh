#!/system/bin/sh

bin=./jpeg-xt
num=10

chmod 755 $bin
time ./hdr-decoder.sh $bin $num
time ./ldr-decoder.sh $bin $num
