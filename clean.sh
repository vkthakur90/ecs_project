#!/bin/bash 

HOME_DIR=`pwd`
BIN_DIR=$HOME_DIR/bin 
SRC_DIR=$HOME_DIR/src 
OBJ_DIR=$SRC_DIR/obj 
MOD_DIR=$SRC_DIR/mod 
LIB_DIR=$HOME_DIR/lib
INCLUDE_PATH=$HOME_DIR/include

echo "Cleaning"

rm -rf $OBJ_DIR/*
rm -rf $BIN_DIR/* 
rm -rf $LIB_DIR/*