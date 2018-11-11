#ifndef SYSTEM_H
#define SYSTEM_H

#include "DAO/DAO.hpp"
#include "Page.hpp"
#include "User.hpp"
#include "DAO/DAOImplementations/SystemDAO.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

class System : public Page {
    private:
        std::vector<int> loggedUsers;
        std::vector<int> registeredUsers;
        int id;

        void showMenu(); 
        bool initializeDB(); 
        
    public:

        System();

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

        /**
         * Initialize the application
         * 
         * @return:
         *           bool   true when system is closed
         *                  false when something got wrong 
         **/
        bool initialize();

        void showMeu();

        int getid();
};

#endif