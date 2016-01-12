#!/bin/sh
rm -rf cmakebuild
CMaker project:meloton src:*.cpp,*.cc,*.hpp head:*.h lib:./lib/libprotobuf.a,./lib/libuv.a
cd cmakebuild
#cmake ./
#make
