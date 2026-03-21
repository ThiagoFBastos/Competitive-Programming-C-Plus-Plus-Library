#!/bin/bash

set -e

BUILD_DIR=build

echo "==> Compilando"
cmake --build $BUILD_DIR

echo "==> Rodando testes"
./$BUILD_DIR/test