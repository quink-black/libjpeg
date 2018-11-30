#!/system/bin/sh

bin=./djpeg-static
num=10

chmod 755 $bin
time ./ldr-decoder-turbo.sh $bin $num
time ./hdr-decoder-turbo.sh $bin $num
