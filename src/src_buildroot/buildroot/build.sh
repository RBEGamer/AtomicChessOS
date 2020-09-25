#!/bin/bash
echo "--- STARTING BUILD ---"
pwd
ls
env


make distclean
echo "-- COPY CONFIG FILE --"
cp ./config_backup ./.config


# make clean stuff
rm -Rf ./output/build/.root

make atcgui-dirclean && rm -Rf ./dl/atcgui/
make atcctl-dirclean && rm -Rf ./dl/atcctl/
make atctp-dirclean && rm -Rf ./dl/atctp/


echo "--BUILD FIRT ITERATION --"

make


echo "-- PATCH config.txt --"



#dtoverlay=i2c-rtc,ds3231

echo "dtparam=i2c=on" >> ./output/images/rpi-firmware/config.txt
echo 'dtparam=i2c1=on' >> ./output/images/rpi-firmware/config.txt
echo 'dtparam=i2c_arm=on' >> ./output/images/rpi-firmware/config.txt
echo 'dtparam=spi=on' >> ./output/images/rpi-firmware/config.txt
echo 'dtparam=i2s=on' >> ./output/images/rpi-firmware/config.txt
echo 'dtparam=audio=on' >> ./output/images/rpi-firmware/config.txt
echo 'dtoverlay=hifiberry-dac' >> ./output/images/rpi-firmware/config.txt
echo 'dtoverlay=i2s-mmap' >> ./output/images/rpi-firmware/config.txt

cat ./output/images/rpi-firmware/config.txt

echo "--BUILD FINAL --"
make