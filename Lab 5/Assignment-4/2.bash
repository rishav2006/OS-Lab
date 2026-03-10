for ((i=2;i<=100;i++))
do
c=0
for ((j=2;j<i;j++))
do
if [ $((i%j)) -eq 0 ]
then
c=1
break
fi
done

if [ $c -eq 0 ]
then
echo $i
fi
done