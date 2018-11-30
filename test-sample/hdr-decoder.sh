#!/bin/sh

bin=$1
num=$2

sample="10-Shiodome_Stairs_3k \
    PaperMill_E_3k \
    WoodenDoor_Ref"

for j in $(seq 1 $num)
do
    echo hdr $j
    for i in $sample
    do
        $bin $i-hdr.jpg $i-hdr.ppm >/dev/null 2>&1
    done
done
