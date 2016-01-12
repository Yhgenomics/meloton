#!/bin/sh
rm -rf cmakebuild
CMaker project:meloton src:*.cpp,*.cc,*.hpp head:*.h lib:./lib/libprotobuf.a,./lib/libuv.a,./lib/libmaraton.a
cd cmakebuild
cmake ./
make -j 4
