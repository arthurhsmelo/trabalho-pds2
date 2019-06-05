#ifndef SYSTEMSCREEN_H
#define SYSTEMSCREEN_H

#include "views/MainScreen.hpp"
#include "exceptions/Exception.hpp"

/**
 *  Classe view para as opções de login/logout do sistema
 */
class SystemScreen : public MainScreen {
  public:
    /**
     *  Mostra o menu de sistema
     */
    void showMenu();
    /**
     *  Requisita os dados de login.
     *  Comunica com o System para logar o usuário.
     */
    void requestLogin();
    /**
     *  Comunica com o System para "deslogar" o usuário.
     */
    void requestLogout();
    /**
     *  Requisita os dados de signup.
     *  Comunica com o System para criar um novo usuário.
     *  
     *  @param bool flag para logar o usuário recém criado.
     */
    void requestSignup(bool);
    /**
     *  Comunica com o System para apagar o usuário.
     */
    void requestSignout();

};

#endif