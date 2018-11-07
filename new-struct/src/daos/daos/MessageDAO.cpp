#include "daos/daos/MessageDAO.hpp"

string MessageDAO::getPrimaryKey() {
    return "message";
};
string MessageDAO::getTableName() {
    return "message_id";
};