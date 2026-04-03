#!/bin/bash

set -e

DIR="$(cd "$(dirname "$0")" && pwd)"

BUILD_DIR=$DIR/../build
BUILD_TYPE=Release
SRC=$DIR/..

cd $SRC

echo "==> Instalando dependências (Conan)"
conan install . \
  --output-folder=$BUILD_DIR \
  --build=missing \
  -s build_type=$BUILD_TYPE

echo "==> Configurando projeto (CMake)"
cmake -S $SRC -B $BUILD_DIR \
  -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE