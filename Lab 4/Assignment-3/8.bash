echo "Enter file name"
read f

if [ -f $f ]
then
awk '{print $NF}' $f | sort
else
echo "File not found"
fi