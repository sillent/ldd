#!/bin/bash

module="mymodule"
device="scull"
mode="644"

/sbin/insmod ./$module.ko $* || exit 1

rm -f /dev/${device}[0-3]

major=$(awk \"$2==\"$module\" "{print \$1}" /proc/devices)

for i in `seq 0 3`
do
    mknod /dev/${device}$i c $major $i
done

group="wheel"
grep -q '^staff:' /etc/group || group="wheel"
chgrp $group /dev/${device}[0-3]
chmod $mode /dev/${device}[0-3]
