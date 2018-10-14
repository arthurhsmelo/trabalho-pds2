CC=g++
CFLAGS=-std=c++11 -Wall

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${BUILD_DIR}/main

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
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/System.hpp ${INCLUDE_DIR}/User.hpp ${INCLUDE_DIR}/Post.hpp ${INCLUDE_DIR}/Search.hpp ${INCLUDE_DIR}/Message.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# app
${BUILD_DIR}/main: ${BUILD_DIR}/System.o ${BUILD_DIR}/User.o ${BUILD_DIR}/Post.o ${BUILD_DIR}/Search.o ${BUILD_DIR}/Message.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/main ${BUILD_DIR}/*.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/* 