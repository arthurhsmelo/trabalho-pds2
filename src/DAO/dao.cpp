#include "DAO/dao.hpp"

DAO::DAO() {
    this->dbStatus = sqlite3_open("database.db", &(this->sqliteConn));
    if( this->dbStatus ) {
        std::cout << "Não foi possível abrir a base de dados: " << sqlite3_errmsg(this->sqliteConn) << std::endl; 
    }
}

int DAO::callback(void *data, int numberOfCols, char **rowValues, char **colsNames) {
    auto self = reinterpret_cast<DAO*>(data);
    self->setNumberOfCols(numberOfCols); 
    self->setRowValues(rowValues); 
    self->setColsNames(colsNames);  

    self->fetchedRows.push_back(self->fetchRow());
    return 0;
}

DAO* DAO::getInstance() {
    if(_instance == NULL) 
        _instance = new DAO();
    return _instance;
}

map<string, string> DAO::fetchRow() {
    map <string, string> row;
    int numberOfCols = this->returnedRow.numberOfCols;
    vector<string> rowValues = this->returnedRow.rowValues;
    vector<string> colsNames = this->returnedRow.colsNames; 
    string currentValue, currentColumn;

    for(int i = 0; i < numberOfCols; i++){
        currentColumn = colsNames.at(i);
        currentValue  = rowValues.at(i);
        
        row.insert(std::pair <string, string> (currentColumn, currentValue)); 
    }

    return row;
}

vector<map<string, string>> DAO::select(string sql) {
    this->dbStatus = sqlite3_exec(this->sqliteConn, sql.c_str(), &callback, this, &(this->zErrMsg));
     
    if( this->dbStatus != SQLITE_OK ) {
        std::cout << "SQL error: " << string(zErrMsg) << std::endl;
        sqlite3_free(zErrMsg);
        
        map <string, string> row;
        row.insert(std::pair <string, string> ("Error", string(zErrMsg)));

        this->fetchedRows.push_back(row); 
    } 

    for (auto row : this->fetchedRows) {
        for (auto field : row) {
            std::cout << field.first << ": " << field.second << " - ";
        }
        std::cout << std::endl;
    }

    return this->fetchedRows;
}

void DAO::exec(string sql) {
    this->dbStatus = sqlite3_exec(this->sqliteConn, sql.c_str(), &callback, this, &(this->zErrMsg));
};

bool DAO::insert(string sql) {
    exec(sql);
     
    if( this->dbStatus != SQLITE_OK ) {
        std::cout << "Erro ao inserir: " << string(this->zErrMsg) << std::endl;
        sqlite3_free(zErrMsg);
        return false;        
    }
    return true;
};

bool DAO::update(string sql) {
    exec(sql);
     
    if( this->dbStatus != SQLITE_OK ) {
        std::cout << "Erro ao atualizar: " << string(this->zErrMsg) << std::endl;
        sqlite3_free(zErrMsg);
        return false;        
    }
    return true;
};

bool DAO::remove(string sql) {
    exec(sql);
     
    if( this->dbStatus != SQLITE_OK ) {
        std::cout << "Erro ao deletar: " << string(this->zErrMsg) << std::endl;
        sqlite3_free(zErrMsg);
        return false;        
    }
    return true;
};

void DAO::setNumberOfCols(int numberOfCols) {
    this->returnedRow.numberOfCols = numberOfCols;
};

void DAO::setRowValues(char** rowValues) {
    vector<string> v(rowValues, rowValues + this->getNumberOfCols());
    this->returnedRow.rowValues = v; 
};

void DAO::setColsNames(char** colsNames) {
    vector<string> v(colsNames, colsNames + this->getNumberOfCols());
    this->returnedRow.colsNames = v;
};

int DAO::getNumberOfCols() {
    return this->returnedRow.numberOfCols;
};

vector<string> DAO::getColsNames() {
    return this->returnedRow.colsNames;
};

sqlite3* DAO::getConnection() {
    return this->sqliteConn;
};

DAO * DAO::_instance = NULL;