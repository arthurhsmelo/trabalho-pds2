#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>
#include "User.hpp"

namespace System {
    class System {
        private:
            std::vector<int> loggedUsers;
            std::vector<int> registeredUsers;
            int id;


        public:

            /**
             * Login and Logout          
             * @params:  std::string username
             *           std::string password
             * 
             * @return:
             *           bool   true if was a successful operation 
             **/
            bool login(std::string, std::string);
            bool logout(std::string);

            /**
             * Signin and Signout          
             * @params:  User user
             *           std::string userName
             * 
             * @return:
             *           int    new User id
             *           bool   true if was a successful operation 
             **/
            int signup(User::User);
            bool signout(std::string);   


            int getid();
    };
}

#endif