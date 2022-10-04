gcc ex4.c -o ex4 -lm

time -p ./ex4 10000000 1
time -p ./ex4 10000000 2
time -p ./ex4 10000000 4
time -p ./ex4 10000000 10
time -p ./ex4 10000000 100
