set -e


DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILDDIR=$DIR/build

if [ ! -d $DIR/build ]; then
mkdir $DIR/build
fi

g++ -O2 -m32 -I./libs/zeex -c $DIR/libs/zeex/fakeamx.cpp -o $BUILDDIR/fakeamx.o

g++ -shared -O2 -m32 -o $DIR/samphp -I$DIR/libs/zeex -I/usr/local/include/php -I/usr/local/include/php/Zend -I/usr/local/include/php/TSRM -I/usr/local/include/php/main -I/usr/local/include/php/sapi/embed -I$DIR/src -I$DIR/libs/zeex -w $DIR/src/*.cpp $BUILDDIR/fakeamx.o -lsampgdk -lrt -lphp5 -lresolv
