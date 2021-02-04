#! /bin/sh
set -x
set -e

mkdir -p config
touch Makefile.am configure.ac
libtoolize -f
aclocal -I m4
autoheader
automake -a -f --foreign
autoconf
