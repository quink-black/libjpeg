#!/bin/sh

set -x

bin=../build/jpeg-xt

sample="10-Shiodome_Stairs_3k \
    PaperMill_E_3k \
    WoodenDoor_Ref"

rm *.jpg *.pfm *.ppm

for i in $sample
do
    mogrify -format pfm $i.hdr
    mogrify -flip $i.pfm
    mogrify -format ppm -depth 8 $i.hdr
done

for i in $sample
do
    $bin -r -q 90 -Q 90 -h -profile c -rR 4 ${i}.pfm ${i}-hdr.jpg
    $bin -q 90 ${i}.ppm ${i}-ldr.jpg
done
