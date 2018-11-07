#include "daos/daos/UserDAO.hpp"

string UserDAO::getPrimaryKey() {
    return "user";
};
string UserDAO::getTableName() {
    return "user_id";
};

User* UserDAO::select(string username) {
    return nullptr;
};
User* UserDAO::select(string username, string password) {
    return nullptr;
};
vector<User> UserDAO::selectList() {
    vector<User> users;
    return users;
};
void UserDAO::insert(User*) {

};
void UserDAO::remove(User*) {

};