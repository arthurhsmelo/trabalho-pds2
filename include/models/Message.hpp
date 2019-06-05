#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using std::string;

class Message {
    private:
        int _id;
        string _content;
        string _senderUser; 
        string _recipientUser; 

    public:
        Message();
        Message(int, string, string, string);
        /* Getters and Setters */
        void setId(int); 
        int getId();
        void setContent(string);
        string getContent();
        void setSenderUser(string);
        string getSenderUser(); 
        void setRecipientUser(string);
        string getRecipientUser(); 
        /* End Get and Set*/
};


#endif