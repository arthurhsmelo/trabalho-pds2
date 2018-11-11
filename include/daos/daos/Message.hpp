#ifndef MESSAGE_H
#define MESSAGE_H

#include "Page.hpp"
#include <string>

using std::string;

namespace Message {
    class Message: public Page {
        private:
            int _id;
            string _content;
            string _senderUser; 
            string _recipientUser; 

        public:
        
        

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
        
            //bloco de funções auxiliares de showMenu
            void printMessage();
            void messageFiller();
            void messageEraser(); 
            void showConversation();                      
            void showMenu() override;
    };
}

#endif