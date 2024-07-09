#! /bin/sh

str="Hello"
numlist=(1 2 3 4 5 6 7 8 9 10);

for i in ${numlist[@]}
do
    echo "n : $i"
done

#length
echo ${#numlist[@]}
echo ${#str}
