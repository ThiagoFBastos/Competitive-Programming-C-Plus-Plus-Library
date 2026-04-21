#!/bin/bash

set -e

DIR="$(cd "$(dirname "$0")" && pwd)"

BUILD_DIR=$DIR/../build
BUILD_TYPE=Release
SRC=$DIR/..

cd $SRC


echo "==> Criando o ambiente virtual"
python3 -m venv env


echo "==> Ativando o ambiente virtual"
source ./env/bin/activate


echo "==> Instalando o Conan"
pip install conan


echo "==> Criando o Conan profile"
conan profile detect --force

export CC=gcc-14
export CXX=g++-14
export CONAN_SETTINGS_COMPILER=gcc
export CONAN_SETTINGS_COMPILER_VERSION=14
export CONAN_SETTINGS_COMPILER_LIBCXX=libstdc++11

echo "==> Instalando dependências (Conan)"
conan install . \
  --output-folder=$BUILD_DIR \
  --build=missing \
  -s build_type=$BUILD_TYPE

echo "==> Configurando projeto (CMake)"
cmake -S . -B $BUILD_DIR \
  -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE