#!/bin/bash

set -e

BUILD_DIR=build

if [ -d $BUILD_DIR ]; then
    echo "==> Compilando"
    cmake --build $BUILD_DIR

    echo "==> Rodando testes"
    ctest --test-dir $BUILD_DIR
else
    echo "o diretório $BUILD_DIR não existe"
fi