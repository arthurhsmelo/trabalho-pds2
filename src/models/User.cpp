#include "models/User.hpp"

User::User(){}

User::User(string name, string userName, string password) {
    this->setId("");
    this->setName(name);
    this->setPassword(password);
    this->setUserName(userName);
    this->setSystemId("");
    this->setQtPosts("");
    this->setQtLikes("");
    this->setQtFollowing("");
    this->setQtFollowers("");
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
        _qtPosts += qtPosts;
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

    void User::setQtFollowing(string qtFollowing){
        _qtFollowing = qtFollowing;       
    }

    string User::getQtFollowing(){
        return _qtFollowing;
    }

    void User::setQtFollowers(string qtFollowers){
        _qtFollowers = qtFollowers;
    }

    string User::getQtFollowers(){
        return _qtFollowers;
    }   
