gcc ex3.c -o ex3
n=3
./ex3 $n &
i=0
while [ $i -lt $(( $n + 1)) ]
do
pstree -h
sleep 5
i=$(( $i + 1))
done
