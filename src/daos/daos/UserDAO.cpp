#include <iostream>
#include "daos/daos/UserDAO.hpp"

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

User* UserDAO::selectUserById(string userId) {

    string query =  "  SELECT * FROM user ";
           query += "  WHERE user_id = '" + userId + "';";

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

void UserDAO::insert(User user) {
    string query = "INSERT INTO user ( ";
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

void UserDAO::remove(User* user) {
    string query = "DELETE FROM user ";
           query += " WHERE username = '" + user->getUserName() + "';";
    DAO::remove(query);
};

void UserDAO::insertFollow(User user, User follower) {
    string query = "INSERT INTO follow ( ";
           query += " username, ";
           query += " follower) ";           
           query += " VALUES ('" + user.getUserName() + "', ";           
           query += " '" + follower.getUserName() + "') ";    
    DAO::insert(query);
};

void UserDAO::removeFollow(User user, User follower) {
    string query = "DELETE FROM follow ";
           query += " WHERE username = '" + user.getUserName() + "' AND follower = '" + follower.getUserName() + "';";
    DAO::remove(query);
};

void UserDAO::removeFollow(User* user) {
    string query = "DELETE FROM follow ";
           query += " WHERE username = '" + user->getUserName() + "' OR follower = '" + user->getUserName() + "' ;";
    DAO::remove(query);
};

vector<User> UserDAO::selectFollow(User user, bool isFollowing){
    
    string field, clause;
    if(isFollowing){
        clause = "username";
        field =  "follower";
    } else {
        clause = "follower";
        field =  "username";
    }

    vector<User> usersFound;
    string query = "SELECT * FROM follow WHERE " + clause + " = '" + user.getUserName() + "'";

    vector<map<string, string>> usersNamesVector = DAO::select(query);

    if(usersNamesVector.size() > 0) {
        for (auto userName: usersNamesVector){
            User* user = select(userName.find(field)->second);
            usersFound.push_back(*user);
        }
    }
    return usersFound;    
}