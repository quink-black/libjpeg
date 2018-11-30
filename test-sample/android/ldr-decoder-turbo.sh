#!/system/bin/sh

bin=$1
num=$2

sample="10-Shiodome_Stairs_3k \
    PaperMill_E_3k \
    WoodenDoor_Ref"

index=1
while [ $(($index)) -le $num ]
do
    echo ldr $index
    index=$(($index + 1))
    for i in $sample
    do
        $bin $i-ldr.jpg >/dev/null
    done
done
