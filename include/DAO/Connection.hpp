#ifndef CONN_H
#define CONN_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include "sqlite3/sqlite3.h"

//Singleton para conectar somente uma vez com o db sqlite3
class Connection {
	static Connection* _instance;
    sqlite3 *sqliteConn;
	
    Connection();
 
public:
	//Retorna a Instãncia 
    static Connection* getInstance();

    sqlite3* getConnection();

};

#endif