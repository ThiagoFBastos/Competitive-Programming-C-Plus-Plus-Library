#!/bin/bash

set -e

BUILD_DIR=build
BUILD_TYPE=Release

echo "==> Instalando dependências (Conan)"
conan install . \
  --output-folder=$BUILD_DIR \
  --build=missing \
  -s build_type=$BUILD_TYPE

echo "==> Configurando projeto (CMake)"
cmake -S . -B $BUILD_DIR \
  -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE