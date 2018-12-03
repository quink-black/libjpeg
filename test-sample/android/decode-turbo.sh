#!/system/bin/sh

bin=./djpeg-static
num=10

sample="10-Shiodome_Stairs_3k \
    PaperMill_E_3k \
    WoodenDoor_Ref"

benchHDR()
{
    index=1
    while [ $(($index)) -le $num ]
    do
        echo hdr $index
        index=$(($index + 1))
        for i in $sample
        do
            $bin $i-hdr.jpg >/dev/null
        done
    done
}

benchLDR()
{
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
}

chmod 755 $bin
time {
    benchHDR
}

time {
    benchLDR
}
