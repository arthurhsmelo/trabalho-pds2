#include <iostream>
#include "models/Post.hpp"
#include "daos/daos/PostDAO.hpp"
#include <string>
#include <vector>

using namespace std;

Post::Post(){}

void Post::setId(int id){
    this->_id = id;
}

int Post::getId(){
    return this->_id;
}

void Post::setContent(std::string message){
    this->_content = message;
}

std::string Post::getContent(){
    return this->_content;
}

void Post::setQtLikes(int likes){
    this->_qtLikes = likes;
}

int Post::getQtLikes(){
    return this->_qtLikes;
}

void Post::setQtReplies(int replies){
    this->_qtReplies = replies;
}

int Post::getQtReplies(){
    return this->_qtReplies;
}

void Post::setQtReposts(int reposts){
    this->_qtReposts = reposts;
}

int Post::getQtReposts(){
    return this->_qtReposts;
}

void Post::setIsReply(bool yesOrNo){
    this->_isReply = yesOrNo;
}

bool Post::getIsReply(){
    return this->_isReply;
}

void Post::setIsRepost(bool yesOrNo){
    this->_isRepost = yesOrNo;
}

bool Post::getIsRepost(){
    return this->_isRepost;
}

void Post::setUser(User user){
    this->user = user;
}

User Post::getUser(){
    return this->user;
}

void Post::createPost(){
    PostDAO postDAO;

    postDAO.insertPost(*this);
}

void Post::updatePost(){   
    PostDAO postDAO;

    postDAO.updatePost(*this);
}

void Post::deletePost(){
    PostDAO postDAO;
   
    postDAO.deletePost(*this);
}
