#! /bin/sh

echo "Enter a number : "
read num
temp=$num
rev=0

while [ $temp -ne 0 ]
do
    digit=`expr $temp % 10`
    rev=`expr $rev \* 10 + $digit`
    temp=`expr $temp / 10`
done

if [ $num -eq $rev ]
then
    echo "$num is a Palindrome"
else
    echo "$num is not a Palindrome"
fi
