ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
ls -i _ex1.txt | tee ex1.txt
ls -i _ex1_1.txt | tee -a ex1.txt
ls -i _ex1_2.txt | tee -a ex1.txt
