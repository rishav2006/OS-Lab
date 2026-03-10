echo "Enter first file"
read f1
echo "Enter second file"
read f2

if [ -f $f1 ] && [ -f $f2 ]
then
cat $f1 > $f2
cat $f2 >> $f1
else
echo "File does not exist"
fi