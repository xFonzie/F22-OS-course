gcc subscriber.c -o sub -lm
gcc publisher.c -o pub -lm
i=0
while [ $i -lt $1 ]
do
gnome-terminal -- ./sub
i=$(( $i + 1))
done
./pub $1
