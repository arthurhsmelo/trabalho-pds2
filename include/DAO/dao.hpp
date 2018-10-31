#ifndef DAO_H
#define DAO_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include "sqlite3/sqlite3.h"

using std::string;
using std::map;
using std::vector;

struct row {
    int numberOfCols;
    vector<string> rowValues;
    vector<string> colsNames;
};

//Singleton para conectar somente uma vez com o db sqlite3
class DAO {
	static DAO* _instance;
	char *zErrMsg = 0;
	int dbStatus;
    sqlite3 *sqliteConn;
    row returnedRow;
    vector<map<string, string>> fetchedRows;
	
    DAO();
    static int callback(void*, int, char**, char **);
    void exec(string);
 
public:
	//Retorna a Instãncia 
    static DAO* getInstance();
	//Retorna um map com as chaves sendo as colunas, e os os valores o valor correspondente a cada coluna
    vector<map<string, string>> select(string);
    bool insert(string);
    bool remove(string);
    bool update(string);

    map<string, string> fetchRow();

    void setNumberOfCols(int);
    void setRowValues(char**);
    void setColsNames(char**);
    
    int getNumberOfCols();
    vector<string> getColsNames();

    sqlite3* getConnection();

};

#endif