#include "DAO/Connection.hpp"

Connection::Connection() {

}

Connection* Connection::getInstance() {
    if(_instance == NULL) 
        _instance = new Connection();
    return _instance;
}

sqlite3* Connection::getConnection() {
    return this->sqliteConn;
};

Connection * Connection::_instance = NULL;