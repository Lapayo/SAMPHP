set -e


DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILDDIR=$DIR/build

if [ ! -d $DIR/build ]; then
mkdir $DIR/build
fi

g++ -shared -O2 -m32 -o $BUILDDIR/samphp -I/usr/local/include/php -I/usr/local/include/php/Zend -I/usr/local/include/php/TSRM -I/usr/local/include/php/main -I/usr/local/include/php/sapi/embed -I$DIR/src -I$DIR/libs/zeex -w $DIR/src/*.cpp $DIR/libs/zeex/*.cpp -lsampgdk -lrt -lphp5 -lresolv
