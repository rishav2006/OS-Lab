echo "Enter year"
read y

if [ $((y%400)) -eq 0 ] || { [ $((y%4)) -eq 0 ] && [ $((y%100)) -ne 0 ]; }
then
echo "Leap Year"
else
echo "Not Leap Year"
fi