#include "daos/daos/MessageDAO.hpp"

#include <iostream>

using std::string;
using std::to_string;

string MessageDAO::getPrimaryKey() {
    return "message_id";
};

string MessageDAO::getTableName() {
    return "message";
};

void MessageDAO::createMessage(Message novo){              
    
    string query = "INSERT INTO message ( ";
           query += " message_id, ";
           query += " content, ";
           query += " sender_user, ";
           query += " recipient_user )";       
           query += " VALUES ('" + this->getNextId() + "', ";
           query += " '" + novo.getContent() + "', ";
           query += " '" + novo.getSenderUser() + "', ";     
           query += " '" + novo.getRecipientUser() + "' )";       
           
    this->insert(query);
} 

Message MessageDAO::recoverMessageByID(int id){
    Message recovered;
    string query =  "  SELECT * FROM message WHERE message_id =" + to_string(id) + ";";
    vector<map<string, string>> choosed = this->select(query);

    for (auto message: choosed){
        recovered.setId(stoi(message.find("message_id")->second));        
        recovered.setContent(message.find("content")->second);        
        recovered.setSenderUser(message.find("sender_user")->second);        
        recovered.setRecipientUser(message.find("recipient_user")->second);     
    }
    
    return recovered;
}

void MessageDAO::deteleMessage(int messageId){

    string query = "DELETE FROM message WHERE message_id = " + to_string(messageId) + ";";
    this->remove(query);
}

vector<Message> MessageDAO::queryToMessage(vector<map<string, string>> conversation) {
    vector<Message> objects;

    for (auto message: conversation){
        Message temp;

        temp.setId(stoi(message.find("message_id")->second));        
        temp.setContent(message.find("content")->second);        
        temp.setSenderUser(message.find("sender_user")->second);        
        temp.setRecipientUser(message.find("recipient_user")->second);  
        objects.push_back(temp);      
    }
    return objects;
}

vector<Message> MessageDAO::selectConversation(string locutorUser, string interlocutorUser){
    vector<Message> objects;

    string query =  "  SELECT * FROM message ";
           query += "  WHERE (sender_user = '" + locutorUser + "'"; 
           query += "  AND recipient_user = '" + interlocutorUser+ "')";
           query += "  OR (sender_user = '" + interlocutorUser+ "'";
           query += "  AND recipient_user = '" + locutorUser+ "')";
           query += "  ORDER BY message_id;";

    vector<map<string, string>> conversation = this->select(query);

    objects = queryToMessage(conversation);
    return objects;
}

vector<Message> MessageDAO::selectFiveLastMessages(string requesterUser){
    vector<Message> objects;

    string query =  " SELECT DISTINCT * FROM message m1 WHERE NOT EXISTS (";
      	  query +=  " SELECT * FROM message m2 wHERE m2.sender_user = m1.recipient_user AND m1.sender_user =";
          query +=  "m2.recipient_user) AND m1.sender_user = '" + requesterUser;
          query +=  "' OR m1.recipient_user = '" + requesterUser; 
          query +=  "' ORDER BY message_id DESC LIMIT 5";

    vector<map<string, string>> conversation = this->select(query);

    objects = queryToMessage(conversation);

    return objects;
}
