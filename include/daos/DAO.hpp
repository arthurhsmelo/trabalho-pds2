#ifndef DAO_H
#define DAO_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include "lib/sqlite/sqlite3.h"
#include "daos/Connection.hpp"

using std::string;
using std::map;
using std::vector;

struct row {
    int numberOfCols;
    vector<string> rowValues;
    vector<string> colsNames;
};

class DAO {
public:
    DAO();

protected:
    int exec(string);
	//Retorna um map com as chaves sendo as colunas, e os os valores o valor correspondente a cada coluna
    vector<map<string, string>> select(string);
    bool insert(string);
    bool remove(string);
    bool update(string);
    bool createTable(string);
    vector<map<string, string>> getFetchedRows();
    string getNextId(); 
    virtual string getTableName() = 0;
    virtual string getPrimaryKey() = 0;

private: 
	char *zErrMsg = 0;
	int dbStatus;
    sqlite3 *sqliteConn;
    row returnedRow;
    vector<map<string, string>> fetchedRows;

    static int callback(void*, int, char**, char **);
    map<string, string> fetchRow();
    void setNumberOfCols(int);
    void setRowValues(char**);
    void setColsNames(char**);
    int getNumberOfCols();
    vector<string> getColsNames();

};

#endif