sudo dd if=/dev/zero of=./lofs.img bs=100M count=10
sudo losetup --find --show ./lofs.img
sudo mkfs -t ext2 /dev/loop0
mkdir lofsdisk
sudo mount /dev/loop0 ./lofsdisk
