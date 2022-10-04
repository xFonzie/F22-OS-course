gcc ex3.c -o ex3 -lm

time -p ./ex3 10000000 1
time -p ./ex3 10000000 2
time -p ./ex3 10000000 4
time -p ./ex3 10000000 10
time -p ./ex3 10000000 100
