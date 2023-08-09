#!/bin/bash 

HOME_DIR=`pwd`
BIN_DIR=$HOME_DIR/bin 
SRC_DIR=$HOME_DIR/src 
OBJ_DIR=$SRC_DIR/obj 
MOD_DIR=$SRC_DIR/mod 
LIB_DIR=$HOME_DIR/lib
INCLUDE_PATH=$HOME_DIR/include

echo "Cleaning"

rm -rf $OBJ_DIR
rm -rf $BIN_DIR 
rm -rf $LIB_DIR

mkdir -p $OBJ_DIR 
mkdir -p $BIN_DIR 
mkdir -p $LIB_DIR 

cd $OBJ_DIR

for file in $MOD_DIR/iface_impl/*.cpp 
do
    echo "Compiling $file"
    g++ -fPIC -std=c++23 -fopenmp -fmodules-ts -O3 -c $file -I$INCLUDE_PATH
done

for file in $MOD_DIR/classes/*.cpp 
do
    echo "Compiling $file"
    g++ -fPIC -std=c++23 -fopenmp -fmodules-ts -O3 -c $file -I$INCLUDE_PATH
done

for file in $MOD_DIR/function/*.cpp 
do
    echo "Compiling $file"
    g++ -fPIC -std=c++23 -fopenmp -fmodules-ts  -O3 -c $file -I$INCLUDE_PATH
done

echo "Creating Library $LIB_DIR/libvector3d.a"
ar -rcs $LIB_DIR/libvector3d.a $OBJ_DIR/*.o 

echo "Creating Executable $BIN_DIR/test.exe"
g++ --std=c++23 -fopenmp -fmodules-ts $SRC_DIR/main.cpp -o $BIN_DIR/test.exe -I$INCLUDE_PATH -L$LIB_DIR -lvector3d -static 

cd $HOME_DIR  