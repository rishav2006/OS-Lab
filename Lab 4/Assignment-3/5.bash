d=$(date + "%d/%m/%Y")
t=$(date + "%I:%M:%S %p %Z")
h=$(date + "%H")

echo $d
echo $t
if [ $h -lt 12 ]
then
echo "Good morning"
elif [ $h -lt 17 ]
then
echo "Good afternoon"
else
echo "Good evening"
fi