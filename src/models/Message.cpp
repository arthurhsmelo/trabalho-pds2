#include "models/Message.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

Message::Message(){}

Message::Message(int id, string content, string senderUser, string recipientUser) : 
        _id(id), _content(content), _senderUser(senderUser), _recipientUser(recipientUser){}

void Message::setId(int id){
    _id=id;
}

int Message::getId(){
    return _id;
}

void Message::setContent(string content){
    _content=content;
}

string Message::getContent(){
    return _content;
}

void Message::setSenderUser(string senderUser){
    _senderUser=senderUser;
}

string Message::getSenderUser(){
    return _senderUser;
}

void Message::setRecipientUser(string recipientUser){
    _recipientUser=recipientUser;
}

string Message::getRecipientUser(){
    return _recipientUser;
}
