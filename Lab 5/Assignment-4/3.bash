echo "Enter string"
read s

rev=$(echo $s | rev)

if [ "$s" = "$rev" ]
then
echo "Palindrome"
else
echo "Not Palindrome"
fi