echo "Enter directory"
read d

count=0

for f in $d/*
do
if [ -x "$f" ] && [ -f "$f" ]
then
echo $(basename $f)
count=$((count+1))
fi
done

echo $count