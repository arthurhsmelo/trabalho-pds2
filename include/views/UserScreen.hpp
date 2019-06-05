#ifndef USERSCREEN_H
#define USERSCREEN_H

#include "views/MainScreen.hpp"
#include "views/SearchScreen.hpp"

/**
 *  Classe view para as opções do usuario no sistema.
 */
class UserScreen : public MainScreen {
  public:
    /**
     *  Mostra o menu de pesquisa
    */
    void showMenu();

    /**
     *  Mostra os dados do usuario logado
    */
    void showUser(User);

    /**
     *  Mostra os dados de um usuário escolhido
    */
    void showAnotherUser();    

    /**
     *  Mostra os usuarios que seguem o usuario logado ou os que o usuario segue
    */
    void showFollow(User, bool);

    /**
     *  Mostra os dados de um usuário escolhido
     *  @param User usuario que será checado se é seguido ou não pelo usuario logado
    */
    void checkFollow(User);

    /**
     *  Monstrar quantos posts o usuario possiu
     *  @param User Usuario escolhido para retornar a quantidade de posts
    */
    string getQtPosts(User);
};

#endif