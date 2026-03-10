echo "Enter three numbers"
read a b c

if [ $a -gt $b ]
then
if [ $a -gt $c ]
then
g=$a
else
g=$c
fi
else
if [ $b -gt $c ]
then
g=$b
else
g=$c
fi
fi

if [ $a -lt $b ]
then
if [ $a -lt $c ]
then
s=$a
else
s=$c
fi
else
if [ $b -lt $c ]
then
s=$b
else
s=$c
fi
fi

echo "Greatest = $g"
echo "Smallest = $s"