echo "Enter marks"
read m

if [ $m -ge 90 ]
then
echo "O"
elif [ $m -ge 80 ]
then
echo "A"
elif [ $m -ge 70 ]
then
echo "B"
elif [ $m -ge 60 ]
then
echo "C"
elif [ $m -ge 50 ]
then
echo "D"
else
echo "F"
fi