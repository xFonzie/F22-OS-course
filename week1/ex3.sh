mkdir rootfolder
date
sleep 3
ls / -lt > rootfolder/root.txt
date
sleep 3
mkdir homefolder
date
sleep 3
ls ~ -lt > homefolder/home.txt
date
sleep 3
echo "The content of the folder 'rootfolder':"
ls rootfolder
echo "The content of the file 'root.txt':"
cat rootfolder/root.txt
echo "The content of the folder 'homefolder':"
ls homefolder
echo "The content of the file 'home.txt':"
cat homefolder/home.txt
