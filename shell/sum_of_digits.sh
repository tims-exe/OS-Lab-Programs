#! /bin/sh

echo "Enter a number"
read num

sum=0
while [ $num -ne 0 ]
do
    digit=`expr $num % 10`
    num=`expr $num / 10`
    sum=`expr $sum + $digit`
done
echo "Sum is $sum"