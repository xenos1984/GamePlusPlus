#! /bin/sh
set -x
set -e

mkdir -p config
touch Makefile.am configure.ac
aclocal #-I m4
libtoolize -f
autoheader
automake -a -f --foreign
autoconf
