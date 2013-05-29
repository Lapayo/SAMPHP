#bash
g++ -shared -o debug -I /usr/local/include/php -I /usr/local/include/php/Zend -I /usr/local/include/php/TSRM -I /usr/local/include/php/main -I /usr/local/include/php/sapi/embed -I ./src -w src/*.cpp phpembed/src/*.cpp -lsampgdk -lrt -lphp5

#debug helper: Move directly to samp server
cp debug ../samp03/plugins/debug

