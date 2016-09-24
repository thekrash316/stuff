#!/bin/sh

set -e

GTEST_VER=1.8.0
GTEST_TARBALL=release-${GTEST_VER}.tar.gz
GTEST_DIR=googletest-release-${GTEST_VER}/googletest

rm -rf ${GTEST_ZIP}
curl -O --location https://github.com/google/googletest/archive/${GTEST_TARBALL}

rm -rf ${GTEST_DIR}
tar fvxz ${GTEST_TARBALL}

g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o

g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest_main.cc
ar -rv libgtest_main.a gtest_main.o

ln -sf ${GTEST_DIR} googletest

