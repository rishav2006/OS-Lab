echo "Enter username"
read u

who | grep "$u"

if [ $? -eq 0 ]
then
echo "User is logged in"
else
echo "User is not logged in"
fi