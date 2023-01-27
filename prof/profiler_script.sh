#! usr/bin/bash
echo "Enter number of profiles: "
read a

echo `make`

i=1

while [[ $i -le $a ]] ; do
    echo `./renderer`
    echo `gprof renderer > prof/profInfo$i`

    echo `sed -n 6p prof/profInfo$i`
    echo `sed -n 7p prof/profInfo$i`

    (( i += 1 ))
done

