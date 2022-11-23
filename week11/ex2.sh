sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib/x86_64-linux-gnu
sudo mkdir lofsdisk/bin
sudo mkdir lofsdisk/lib64
sudo cp /bin/bash lofsdisk/bin/bash
sudo cp /bin/cat lofsdisk/bin/cat
sudo cp /bin/echo lofsdisk/bin/echo
sudo cp /bin/ls lofsdisk/bin/ls
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu/libtinfo.so.6
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu/libselinux.so.1
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu/libpcre2-8.so.0
sudo ./ex2.out > ex2.txt
echo "\n" >> ex2.txt
sudo chroot lofsdisk ./ex2.out >> ex2.txt
