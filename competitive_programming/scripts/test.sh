#!/bin/bash

set -e

DIR="$(cd "$(dirname "$0")" && pwd)"

BUILD_DIR=$DIR/../build


if [ -d $BUILD_DIR ]; then
    echo "==> Compilando"
    cmake --build $BUILD_DIR

    echo "==> Rodando testes"
    ctest --test-dir $BUILD_DIR
else
    echo "o diretório $BUILD_DIR não existe"
fi