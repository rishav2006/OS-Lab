echo "1 List files"
echo "2 Create directory"
echo "3 Change directory"
echo "4 Remove directory"
echo "5 Create file"
echo "6 Copy file"
echo "7 Remove file"
read ch

case $ch in
1) ls ;;
2) echo "Enter directory name"
   read d
   mkdir $d ;;
3) echo "Enter directory name"
   read d
   cd $d ;;
4) echo "Enter directory name"
   read d
   rmdir $d ;;
5) echo "Enter file name"
   read f
   touch $f ;;
6) echo "Enter source file"
   read s
   echo "Enter destination file"
   read d
   cp $s $d ;;
7) echo "Enter file name"
   read f
   rm $f ;;
*) echo "Invalid choice"
esac