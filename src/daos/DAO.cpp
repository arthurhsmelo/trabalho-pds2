#include "daos/DAO.hpp"

string DAO::getTableName() {
    return "";
};
string DAO::getPrimaryKey() {
    return "";
};


DAO::DAO() {
    Connection *conn = Connection::getInstance();
    this->sqliteConn = conn->getConnection();
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

string DAO::getNextId() {
    string query = "SELECT * FROM ( SELECT MAX("+ this->getPrimaryKey() +") as "+ this->getPrimaryKey() +" FROM "+ this->getTableName() +" ) WHERE "+ this->getPrimaryKey() +" IS NOT NULL";
    vector<map<string, string>> result = this->select(query);
    if(result.size() > 0) {
        int maxId = std::stoi(result.at(0).find(this->getPrimaryKey())->second);
        return std::to_string(maxId + 1);
    } else {
        return "1";
    }    
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
    //Clear old rows
    this->fetchedRows.clear();

    this->dbStatus = sqlite3_exec(this->sqliteConn, sql.c_str(), &callback, this, &(this->zErrMsg));
    if( this->dbStatus != SQLITE_OK ) {
        std::cout << "SQL error: " << string(zErrMsg) << std::endl;
        sqlite3_free(zErrMsg);
        
        map <string, string> row;
        row.insert(std::pair <string, string> ("Error", string(zErrMsg)));

        this->fetchedRows.push_back(row); 
    } 

    return this->fetchedRows;
}

int DAO::exec(string sql) {
    this->dbStatus = sqlite3_exec(this->sqliteConn, sql.c_str(), &callback, this, &(this->zErrMsg));
    return this->dbStatus;
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

bool DAO::createTable(string sql) {
    exec(sql);
    if( this->dbStatus != SQLITE_OK && string(this->zErrMsg).find("already exists") == string::npos) {
        std::cout << "Erro ao criar tabela: " << string(this->zErrMsg) << std::endl;
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