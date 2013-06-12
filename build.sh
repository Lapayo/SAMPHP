set -e

BUILDDIR=./build


g++ -shared -O2 -m32 -o $BUILDDIR/samphp -I/usr/local/include/php -I/usr/local/include/php/Zend -I/usr/local/include/php/TSRM -I/usr/local/include/php/main -I/usr/local/include/php/sapi/embed -I./src -I./libs/zeex -w ./src/*.cpp ./libs/zeex/*.cpp -lsampgdk -lrt -lphp5 -lresolv
