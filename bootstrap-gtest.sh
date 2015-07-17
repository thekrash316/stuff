#!/bin/sh

set -e

GTEST_ZIP=gtest-1.7.0.zip
GTEST_DIR=gtest-1.7.0

rm -rf ${GTEST_ZIP}
curl -O https://googletest.googlecode.com/files/${GTEST_ZIP}

rm -rf ${GTEST_DIR}
unzip ${GTEST_ZIP}

g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o

g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest_main.cc
ar -rv libgtest_main.a gtest_main.o
