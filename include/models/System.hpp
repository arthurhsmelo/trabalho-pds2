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

/**
 *  Classe responsável por armazenar as informações do sistema. 
 *  Esta classe implementa uma técnica conhecida como Singleton para fornecer informações úteis,
 *  como o usuário logado para o resto do sistema. 
 *  @see https://sourcemaking.com/design_patterns/singleton/cpp/1
 */
class System {
	static System* _instance;   /**< A instância da classe */  
    User *loggedUser;         /**< Ponteiro para o usuário logado */  
	
    /**
     *  Construtor privado.
     *  Necessário para a implementação do Singleton.
     */
    System();
    /**
     *  Cria as tabelas do sistema.
     *  Comunica com o SystemDAO para criar as tabelas
     */
    bool initializeDB();
 
  public:
    /**
     *  Destrutor.
     *  Libera a memória ocupada pela conexão com o banco(Connection*) e o usuário logado(*loggedUser).
     */
    ~System();
	  /**
     *  Cria, se ainda não houver uma instância desta classe.
     *  
     *  @return Connection* Ponteiro para a instância única da classe.
     */
    static System* getInstance();
    /**
     *  Retorna usuário logado
     *  
     *  @return User* Ponteiro para o usuário logado.
     */
    User* getLoggedUser();
    /**
     *  Seta usuário logado
     *  
     *  @param User* Ponteiro para o usuário que fará login.
     */
    void setLoggedUser(User*);
    
    /**
     *  Seta o usuário logado
     *  
     *  @param string username para tentar login.
     *  @param string password para tentar login.
     *  
     *  @throws Exception#UserNotFound
     *  @throws Exception#InvalidPassword
     */
    void login(string, string);
    /**
     *  "Desloga" o usuário
     */
    void logout();

    /**
     *  Cria um novo usuário.
     *  Pode também, fazer login do usuário que acabou de criar.
     *  
     *  @param string name do novo usuário.
     *  @param string username do novo usuário.
     *  @param string password do novo usuário.
     *  @param bool flag para dizer se o usário criado será setado como usuário logado.
     *  
     *  @throws Exception#UserAlreadyExists
     */
    void signup(string, string, string, bool);
    /**
     *  Remove o usuário logado da base de dados
     */
    void signout();

    /**
     *  Inicializa o sistema.
     *  Inicializa o banco de dados com #initializeDB e seta #loggedUser como nullptr
     *  
     *  @throws Exception#BadDataBaseInitialization
     */
    void initialize();

};

#endif