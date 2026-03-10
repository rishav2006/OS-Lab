echo "Enter first name"
read n1
echo "Enter second name"
read n2

echo $n1
echo $n2
if [ "$n1" = "$n2" ]
then
echo "Same"
else
echo "Different"
fi