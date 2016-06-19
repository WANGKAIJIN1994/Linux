#!/bin/bash
read -p "please enter ten numbera:" -a Array
echo ${Array[*]}
min=${Array[0]}
max=${Array[0]}
i=0
while [ $i -lt 10 ] 
do
if [ ${Array[$i]} -lt $min ]
then min=${Array[$i]}
elif [ ${Array[$i]} -gt $max ]
then max=${Array[$i]}
fi
i=`expr $i + 1`
done
echo $min $max
exit 0
