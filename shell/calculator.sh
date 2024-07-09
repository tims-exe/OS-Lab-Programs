#! /bin/sh

while [ 1 -eq 1 ]
do
    echo "Enter 2 numbers : "
    read a b
    echo "Select Operation \n1.Addition"
    echo "2.Subtraction\n3.Multiplication"
    echo "4.Division\n5.Modulus\n6.Exit"
    
    read c 
    
    case $c in 
    1)echo "$a + $b = `expr $a + $b`";;
    2)echo "$a - $b = `expr $a - $b`";;
    3)echo "$a * $b = `expr $a \* $b`";;
    4)echo "$a / $b = `expr $a / $b`";;
    5)echo "$a % $b = `expr $a % $b`";;
    6)exit;;
    *)echo "Invalid"
    esac
done