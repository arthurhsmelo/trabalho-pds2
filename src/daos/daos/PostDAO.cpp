#include "daos/daos/PostDAO.hpp"

string PostDAO::getPrimaryKey() {
    return "post";
};
string PostDAO::getTableName() {
    return "post_id";
};