set -e
SRCDIR=${HOME}/php5.4-source
DISTDIR=${HOME}/dist
rm -rf $SRCDIR

PHP5="php-5.6.2"

PHPFEATURES="--disable-cli --disable-cgi --enable-embed=shared --disable-zts --with-sqlite3 --enable-pdo --with-pdo-mysql --with-pdo-sqlite --with-mysqli --enable-mbstring \
"

mkdir -p ${SRCDIR}
if [ ! -f ${DISTDIR} ] 
then
mkdir -p ${DISTDIR}
fi

cd ${DISTDIR}

if [ ! -f ${DISTDIR}/${PHP5}.tar.gz ] 
then
    wget -c http://us.php.net/get/${PHP5}.tar.gz/from/this/mirror/
    mv index.html ${PHP5}.tar.gz
fi


echo ---------- Unpacking downloaded archives. This process may take several minutes! ----------

cd ${SRCDIR}

# Unpack them all
echo Extracting ${PHP5}...
tar xzf ${DISTDIR}/${PHP5}.tar.gz
echo Done.


#PHP 5
echo ###################
echo Compile PHP
echo ###################
cd ${SRCDIR}/${PHP5}
export CXXFLAGS="-m32"
export LDFLAGS="-m32"
export CPPFLAGS="-m32"
./configure ${PHPFEATURES}
make
make install

#register module
ldconfig

exit 0
