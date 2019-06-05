#ifndef POSTSCREEN_H
#define POSTSCREEN_H

#include "views/MainScreen.hpp"
#include "models/Post.hpp"

/**
 *  Classe view para as opções do usuario no sistema.
 */
class PostScreen : public MainScreen {
  public:
    /**
     *  Mostra e o feed
    */
    void showMenu();
    /**
     *  Mostra a selecao de posts para o usuário visualizar
    */
    void postChoice();
    /**
     *  Mostra as opcoes de interacao com um post
    */
    void postOptions(Post);
    /**
     *  Permite ao usuário criar um novo post
    */
    void newPost();
    /**
     *  Permite ao usuário comentar em um post
    */
    void postComment(Post);
    /**
     *  Printa um post e seus atributos passado por parametro
    */
    void showPost(Post);
    /**
     * Printa o feed
    */
    void printPost(int, Post);
};

#endif
