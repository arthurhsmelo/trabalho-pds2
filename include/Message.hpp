#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

namespace Message {
    class Message {
         private:
            int id;
            std::string content;
            int senderId;
            int recipientId;

        public:  
            /* Getters and Setters */
            void setId(int);
            int getId();
            void setContent(std::string);
            std::string getContent();
            void setSenderId(int);
            int getSenderId();
            void setRecipientId(int);
            int getRecipientId();
            /* End Get and Set*/
    };
}

#endif