#include "models/User.hpp"
#include "daos/daos/UserDAO.hpp"

User::User(){}

User::User(string name, string userName, string password) {
    this->setId("");
    this->setName(name);
    this->setPassword(password);
    this->setUserName(userName);
    this->setSystemId("");
    this->setQtPosts("0");
    this->setQtLikes("0");
    this->setQtFollowing("0");
    this->setQtFollowers("0");
}

void User::setId(string id){
        _id = id;
}

string User::getId(){
    return _id;
}

void User::setName(string name){
    _name = name;
}

string User::getName(){
    return _name;
}

void User::setPassword(string password){
    _password = password;
}

string User::getPassword(){
    return _password;
}

void User::setUserName(string userName){
    _userName = userName;
}

string User::getUserName(){
    return _userName;
}

void User::setSystemId(string systemId){
    _systemId = systemId;
}

string User::getSystemId(){
    return _systemId;
}      

void User::setQtPosts(string qtPosts){
    _qtPosts = qtPosts;
}

string User::getQtPosts(){
    return _qtPosts;
}

void User::setQtLikes(string qtLikes){
    _qtLikes = qtLikes;
}

string User::getQtLikes(){
    return _qtLikes;
}

vector<User> User::getFollowings(){    
    UserDAO userDAO;
    return userDAO.selectFollow(*this, true);    
}

vector<User> User::getFollowers(){    
    UserDAO userDAO;
    return userDAO.selectFollow(*this, false);    
}

void User::setQtFollowing(string qtFollowing){
    _qtFollowing = qtFollowing;       
}

string User::getQtFollowing(){    
    return std::to_string(User::getFollowings().size());
}

void User::setQtFollowers(string qtFollowers){
    _qtFollowers = qtFollowers;
}

string User::getQtFollowers(){
    return std::to_string(User::getFollowers().size());
}   

void User::setFollowings(User user){    
    UserDAO userDAO;
    userDAO.insertFollow(*this, user);
}       

bool User::checkIsFollowing(User user){
    vector<User> usersVector = this->getFollowings();

    if(usersVector.size() > 0) {
        for (auto objUser: usersVector){
            if(objUser.getUserName() == user.getUserName())
                return true;
        }
    }

    return false;
}
        
void User::unfollow(User user){
    UserDAO userDAO;
    userDAO.removeFollow(*this, user);
}