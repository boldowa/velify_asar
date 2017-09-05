#!/bin/sh
cd `dirname "$0"`
if test -r Makefile; then
  make clean
fi
rm -rf CMake* cmake_* Makefile
