#ifndef SYSTEM_H
#define SYSTEM_H

#include "exceptions/Exception.hpp"
#include "models/User.hpp"
#include "daos/daos/UserDAO.hpp"
#include "daos/daos/SystemDAO.hpp"
#include <string>

using std::string;
using std::cout;
using std::endl;

//Singleton para armazenar as informações do sistema
class System {
	static System* _instance;
    User *loggedUser;
	
    System();
    bool initializeDB();
 
  public:
    ~System();
	  //Retorna a Instãncia 
    static System* getInstance();
    User* getLoggedUser();
    void setLoggedUser(User*);
    
    /**
     * Login and Logout          
     * @params:  string username
     *           string password
     * 
     * @return:
     *           int   user id
     **/
    void login(string, string);
    void logout();

    /**
     * Signin          
     * @params:  User user
     *           string userName
     * 
     * @return:
     *           int    new User id
     *           bool   true if was a successful operation 
     **/
    void signup(string, string, string, bool);
    void signout();

    /**
     * Initialize the application
     **/
    void initialize();
};

#endif