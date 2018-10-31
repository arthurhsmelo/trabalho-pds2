CC=g++
C=gcc
CFLAGS=-std=c++11 -Wall

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${BUILD_DIR}/main

# Sqlite
${BUILD_DIR}/sqlite3.o: ${INCLUDE_DIR}/sqlite3/sqlite3.h ${INCLUDE_DIR}/sqlite3/sqlite3.c
	${C} -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION -I ${INCLUDE_DIR}/ -c ${INCLUDE_DIR}/sqlite3/sqlite3.c -o ${BUILD_DIR}/sqlite.o

# DAO

# Main DAO
${BUILD_DIR}/dao.o: ${INCLUDE_DIR}/DAO/dao.hpp ${SRC_DIR}/DAO/dao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/DAO/dao.cpp -o ${BUILD_DIR}/dao.o

# System
${BUILD_DIR}/System.o: ${INCLUDE_DIR}/System.hpp ${SRC_DIR}/System.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/System.cpp -o ${BUILD_DIR}/System.o

# User
${BUILD_DIR}/User.o: ${INCLUDE_DIR}/User.hpp ${SRC_DIR}/User.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/User.cpp -o ${BUILD_DIR}/User.o

# Post
${BUILD_DIR}/Post.o: ${INCLUDE_DIR}/Post.hpp ${SRC_DIR}/Post.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Post.cpp -o ${BUILD_DIR}/Post.o

# Search
${BUILD_DIR}/Search.o: ${INCLUDE_DIR}/Search.hpp ${SRC_DIR}/Search.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Search.cpp -o ${BUILD_DIR}/Search.o

# Message
${BUILD_DIR}/Message.o: ${INCLUDE_DIR}/Message.hpp ${SRC_DIR}/Message.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Message.cpp -o ${BUILD_DIR}/Message.o

# main
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/System.hpp ${INCLUDE_DIR}/User.hpp ${INCLUDE_DIR}/Post.hpp ${INCLUDE_DIR}/Search.hpp ${INCLUDE_DIR}/Message.hpp ${INCLUDE_DIR}/sqlite3/sqlite3.h ${INCLUDE_DIR}/DAO/dao.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# app
${BUILD_DIR}/main: ${BUILD_DIR}/System.o ${BUILD_DIR}/User.o ${BUILD_DIR}/Post.o ${BUILD_DIR}/Search.o ${BUILD_DIR}/Message.o ${BUILD_DIR}/sqlite3.o ${BUILD_DIR}/dao.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/main ${BUILD_DIR}/*.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean_linux:
	rm -rf ${BUILD_DIR}/*.o 

clean_windows:
	del /S "%dir%\build\*.o"

run:
	./build/main.exe