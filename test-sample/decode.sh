#!/bin/bash

bin=../build/jpeg-xt
num=10
sample="10-Shiodome_Stairs_3k \
    PaperMill_E_3k \
    WoodenDoor_Ref"

benchHDR()
{
    for j in $(seq 1 $num)
    do
        echo hdr $j
        for i in $sample
        do
            $bin $i-hdr.jpg $i-hdr.ppm &>/dev/null
        done
    done
}

benchLDR()
{
    for j in $(seq 1 $num)
    do
        echo ldr $j
        for i in $sample
        do
            $bin $i-ldr.jpg $i-ldr.ppm >/dev/null 2>&1
        done
    done
}

time {
    benchHDR
}

time {
    benchLDR
}
