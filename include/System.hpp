#ifndef SYSTEM_H
#define SYSTEM_H

#include "DAO/DAO.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "User.hpp"

using std::cout;
using std::endl;

class System {
private:
    std::vector<int> loggedUsers;
    std::vector<int> registeredUsers;
    int id;

    void showMenu(); 
    bool initializeDB(); 
    void createSystemTable(DAO*);
    void createUserTable(DAO*);
    void createPostTable(DAO*);
    void createMessageTable(DAO*);
    
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


    int getid();
};

#endif