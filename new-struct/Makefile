CC=g++
C=gcc
CFLAGS=-std=c++11 -Wall

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: main

####################################################
#                                                  #
#                       DAOS                       #
#                                                  #
####################################################

# SQLITE Connection Singleton
Connection.o: ${INCLUDE_DIR}/daos/Connection.hpp ${SRC_DIR}/daos/Connection.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/Connection.cpp -o ${BUILD_DIR}/Connection.o

# Main DAO
DAO.o: ${INCLUDE_DIR}/daos/DAO.hpp ${SRC_DIR}/daos/DAO.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/DAO.cpp -o ${BUILD_DIR}/DAO.o

# System DAO
SystemDAO.o: ${INCLUDE_DIR}/daos/daos/SystemDAO.hpp ${SRC_DIR}/daos/daos/SystemDAO.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/daos/SystemDAO.cpp -o ${BUILD_DIR}/SystemDAO.o

# User DAO
UserDAO.o: ${INCLUDE_DIR}/daos/daos/UserDAO.hpp ${SRC_DIR}/daos/daos/UserDAO.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/daos/UserDAO.cpp -o ${BUILD_DIR}/UserDAO.o

# Message DAO
MessageDAO.o: ${INCLUDE_DIR}/daos/daos/MessageDAO.hpp ${SRC_DIR}/daos/daos/MessageDAO.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/daos/MessageDAO.cpp -o ${BUILD_DIR}/MessageDAO.o

# Post DAO
PostDAO.o: ${INCLUDE_DIR}/daos/daos/PostDAO.hpp ${SRC_DIR}/daos/daos/PostDAO.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/daos/PostDAO.cpp -o ${BUILD_DIR}/PostDAO.o

# Search DAO
SearchDAO.o: ${INCLUDE_DIR}/daos/daos/SearchDAO.hpp ${SRC_DIR}/daos/daos/SearchDAO.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/daos/daos/SearchDAO.cpp -o ${BUILD_DIR}/SearchDAO.o


####################################################
#                                                  #
#                    SCREENS                       #
#                                                  #
####################################################

# Main Screen
MainScreen.o: ${INCLUDE_DIR}/views/MainScreen.hpp ${SRC_DIR}/views/MainScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/MainScreen.cpp -o ${BUILD_DIR}/MainScreen.o

# Message Screen
MessageScreen.o: ${INCLUDE_DIR}/views/MessageScreen.hpp ${SRC_DIR}/views/MessageScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/MessageScreen.cpp -o ${BUILD_DIR}/MessageScreen.o

# Post Screen
PostScreen.o: ${INCLUDE_DIR}/views/PostScreen.hpp ${SRC_DIR}/views/PostScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/PostScreen.cpp -o ${BUILD_DIR}/PostScreen.o

# Search Screen
SearchScreen.o: ${INCLUDE_DIR}/views/SearchScreen.hpp ${SRC_DIR}/views/SearchScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/SearchScreen.cpp -o ${BUILD_DIR}/SearchScreen.o

# System Screen
SystemScreen.o: ${INCLUDE_DIR}/views/SystemScreen.hpp ${SRC_DIR}/views/SystemScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/SystemScreen.cpp -o ${BUILD_DIR}/SystemScreen.o

# User Screen
UserScreen.o: ${INCLUDE_DIR}/views/UserScreen.hpp ${SRC_DIR}/views/UserScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/UserScreen.cpp -o ${BUILD_DIR}/UserScreen.o

####################################################
#                                                  #
#                     MODELS                       #
#                                                  #
####################################################

# User Model
User.o: ${INCLUDE_DIR}/models/User.hpp ${SRC_DIR}/models/User.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/User.cpp -o ${BUILD_DIR}/User.o

# Message Model
Message.o: ${INCLUDE_DIR}/models/Message.hpp ${SRC_DIR}/models/Message.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Message.cpp -o ${BUILD_DIR}/Message.o

# Post Model
Post.o: ${INCLUDE_DIR}/models/Post.hpp ${SRC_DIR}/models/Post.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Post.cpp -o ${BUILD_DIR}/Post.o

# Search Model
Search.o: ${INCLUDE_DIR}/models/Search.hpp ${SRC_DIR}/models/Search.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Search.cpp -o ${BUILD_DIR}/Search.o

# System Model
System.o: ${INCLUDE_DIR}/models/System.hpp ${SRC_DIR}/models/System.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/System.cpp -o ${BUILD_DIR}/System.o

####################################################
#                                                  #
#                       APP                        #
#                                                  #
####################################################

# main
main.o: ${INCLUDE_DIR}/daos/Connection.hpp ${INCLUDE_DIR}/daos/DAO.hpp ${INCLUDE_DIR}/daos/daos/SystemDAO.hpp ${INCLUDE_DIR}/daos/daos/UserDAO.hpp ${INCLUDE_DIR}/daos/daos/MessageDAO.hpp ${INCLUDE_DIR}/daos/daos/PostDAO.hpp ${INCLUDE_DIR}/daos/daos/SearchDAO.hpp ${INCLUDE_DIR}/views/MainScreen.hpp ${INCLUDE_DIR}/views/MessageScreen.hpp ${INCLUDE_DIR}/views/PostScreen.hpp ${INCLUDE_DIR}/views/SearchScreen.hpp ${INCLUDE_DIR}/views/SystemScreen.hpp ${INCLUDE_DIR}/views/UserScreen.hpp ${INCLUDE_DIR}/models/User.hpp ${INCLUDE_DIR}/models/Message.hpp ${INCLUDE_DIR}/models/Post.hpp ${INCLUDE_DIR}/models/Search.hpp ${INCLUDE_DIR}/models/System.hpp ${INCLUDE_DIR}/lib/sqlite/sqlite3.h ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# app
main: Connection.o DAO.o SystemDAO.o UserDAO.o MessageDAO.o PostDAO.o SearchDAO.o MainScreen.o MessageScreen.o PostScreen.o SearchScreen.o SystemScreen.o UserScreen.o User.o Message.o Post.o Search.o System.o main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/main ${BUILD_DIR}/*.o ${BUILD_DIR}/lib/sqlite/sqlite.o


# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean_linux:
	rm -rf ${BUILD_DIR}/*.o 

clean_windows:
	del /S "%dir%\build\*.o"

run:
	./build/main.exe

