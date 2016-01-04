del handler\*
del message\*

protoc --cpp_out=../message *.proto
meloton-handler-generator.exe D:\Git\meloton\proto\ D:\Git\meloton\proto\

copy message/MessageUtils.h ../handler/
 
 
pause