#!/bin/bash

set -e

BUILD_DIR=build

echo "==> Compilando"
cmake --build $BUILD_DIR

echo "==> Rodando testes"
ctest --test-dir $BUILD_DIR