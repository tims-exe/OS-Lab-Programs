#!/bin/sh
echo "Enter a Number:"
read num
f=1
i=1
until [ $i -ge `expr $num + 1` ]
do
    f=`expr $f \* $i`
    i=`expr $i + 1`
done
echo "Factorial of $n is $f"
