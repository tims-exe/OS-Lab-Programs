#! /bin/sh

echo "Enter a number :"
read num

b=`expr $num % 2`

if [ $b -eq 0 ]
then
echo "$num is Even"
else
echo "$num is Odd"
fi
