./build.sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILDDIR=$DIR/build

#debug helper: Move directly to samp server
cp $BUILDDIR/samphp $DIR/server-folder/plugins/samphp

