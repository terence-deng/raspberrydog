Raspberry Dog
============
By [Terence Deng](mailto:deng.tooling@gmail.com)

What it is
----------
Watch dog for raspberry pi
* shutdown raspberry pi when the 12th pin (GPIO 1/GPIO18) is set as high
* reboot raspberry pi when the 13th pin (GPIO 2/GPIO27) is set as high

Build Requirements
------------------
Required:
* wiringPi
* apt-get install autoconf automake

How to get started
-------------

```
build.sh
./configure && make
make install
sudo raspberrydog
```
To shutdown the Raspberry Pi, you can connet 12th pin (GPIO 1/GPIO18) with 11th pin (GPIO 0/GPIO17) 
```
+----------+-Rev2-+------+--------+------+-------+
| wiringPi | GPIO | Phys | Name   | Mode | Value |
+----------+------+------+--------+------+-------+
|      0   |  17  |  11  | GPIO 0 | OUT  | High  |   ----> 11th pin
|      1   |  18  |  12  | GPIO 1 | IN   | Low   |   ----> 12th pin
|      2   |  27  |  13  | GPIO 2 | IN   | Low   |   ----> 13th pin
|      3   |  22  |  15  | GPIO 3 | IN   | Low   |
|      4   |  23  |  16  | GPIO 4 | IN   | Low   |
|      5   |  24  |  18  | GPIO 5 | IN   | Low   |
|      6   |  25  |  22  | GPIO 6 | IN   | Low   |
|      7   |   4  |   7  | GPIO 7 | IN   | Low   |
|      8   |   2  |   3  | SDA    | IN   | High  |
|      9   |   3  |   5  | SCL    | IN   | High  |
|     10   |   8  |  24  | CE0    | ALT0 | High  |
|     11   |   7  |  26  | CE1    | ALT0 | High  |
|     12   |  10  |  19  | MOSI   | ALT0 | Low   |
|     13   |   9  |  21  | MISO   | ALT0 | Low   |
|     14   |  11  |  23  | SCLK   | ALT0 | Low   |
|     15   |  14  |   8  | TxD    | ALT0 | High  |
|     16   |  15  |  10  | RxD    | ALT0 | High  |
|     17   |  28  |   3  | GPIO 8 | IN   | Low   |
|     18   |  29  |   4  | GPIO 9 | IN   | Low   |
|     19   |  30  |   5  | GPIO10 | IN   | Low   |
|     20   |  31  |   6  | GPIO11 | IN   | Low   |
+----------+------+------+--------+------+-------+
```

Start it at boot time
-------------
```
cp scripts/debian/init.d/raspberrydog /etc/init.d/
update-rc.d raspberrydog defaults
service raspberrydog start
```
