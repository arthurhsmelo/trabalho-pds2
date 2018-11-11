#include <iostream>
#include "daos/daos/UserDAO.hpp"
#include "models/User.hpp"

using std::string;
using std::to_string;

string UserDAO::getPrimaryKey() {
    return "user_id";
};
string UserDAO::getTableName() {
    return "user";
};

User* UserDAO::select(string userName) {

    string query =  "  SELECT * FROM user ";
           query += "  WHERE username = '" + userName + "';";

    vector<map<string, string>> listUser = DAO::select(query);

    if(listUser.size() <= 0) {
        return nullptr;
    } else {
        User* user = new User();

        for (auto objUser: listUser){
            user->setId(objUser.find("user_id")->second);        
            user->setName(objUser.find("name")->second);
            user->setPassword(objUser.find("password")->second);
            user->setUserName(objUser.find("username")->second);
            user->setSystemId(objUser.find("system_id")->second);
            user->setQtPosts(objUser.find("qt_posts")->second);
            user->setQtLikes(objUser.find("qt_likes")->second);
            user->setQtFollowing(objUser.find("qt_following")->second); 
            user->setQtFollowers(objUser.find("qt_followers")->second);   
        }

        return user;
    }
};

User* UserDAO::select(string userName, string password) {

    string query =  "  SELECT * FROM user ";
           query += "  WHERE username = '" + userName + "' and password = '"+ password +"';";

    vector<map<string, string>> listUser = DAO::select(query);   

    if(listUser.size() <= 0) {
        return nullptr;
    } else {
        User* user = new User();

        for (auto objUser: listUser){
            user->setId(objUser.find("user_id")->second);        
            user->setName(objUser.find("name")->second);
            user->setPassword(objUser.find("password")->second);
            user->setUserName(objUser.find("username")->second);
            user->setSystemId(objUser.find("system_id")->second);
            user->setQtPosts(objUser.find("qt_posts")->second);
            user->setQtLikes(objUser.find("qt_likes")->second);
            user->setQtFollowing(objUser.find("qt_following")->second); 
            user->setQtFollowers(objUser.find("qt_followers")->second);   
        }

        return user;
    }
};

vector<User> UserDAO::selectList() {
    vector<User> users;
    return users;
};

void UserDAO::insert(User user) {
    string query = "INSERT INTO USER ( ";
           query += " user_id, ";
           query += " name, ";
           query += " password, ";
           query += " username, ";
           query += " system_id, ";
           query += " qt_posts, ";
           query += " qt_likes, ";
           query += " qt_following, ";
           query += " qt_followers ) ";
           query += " VALUES ('" + this->getNextId() + "', ";
           query += " '" + user.getName() + "', ";
           query += " '" + user.getPassword() + "', ";
           query += " '" + user.getUserName() + "', ";
           query += " '" +user.getSystemId() + "', ";
           query += " '" +user.getQtPosts() + "', ";
           query += " '" +user.getQtLikes() + "', ";
           query += " '" +user.getQtFollowing() + "', ";
           query += " '" +user.getQtFollowers() + "') ";    
    DAO::insert(query);

};

void UserDAO::remove(User*) {

};