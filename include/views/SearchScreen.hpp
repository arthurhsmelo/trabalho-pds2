#ifndef SEARCHSCREEN_H
#define SEARCHSCREEN_H

#include "views/MainScreen.hpp"
#include "views/UserScreen.hpp"
#include "views/PostScreen.hpp"
#include "models/Search.hpp"
#include <functional>
using std::placeholders::_1;

/**
 *  Classe view para as opções de pesquisa do sistema.
 */
class SearchScreen : public MainScreen {
  public:
    /**
     *  Mostra o menu de pesquisa
     */
    void showMenu();

    /**
     *  Mostra a opcao de pesquisa do usuario
     */
    void showOptionUser();
  private:
    /**
     *  Comunica com o Search para buscar usuários.
     *  Mostra os resultados encontrados
     *  
     *  @param string username a ser buscado 
     */
    void searchUsers(string);
    /**
     *  Comunica com o Search para buscar posts.
     *  Mostra os resultados encontrados
     * 
     *  @param string conteúdo a ser buscado
     */
    void searchPosts(string);
    
    template <class Result>
    /**
     *  Mostra o menu de escolha.
     *  Trata escolhas inválidas e redireciona para as classes User ou Post, para que elas mostrem o resultado escolhido.
     * 
     *  @param vector<Class Result> vetor de resultados
     *  @param std::function<void(Result)> callback para onde a função vai mandar o resultado escolhido
     * 
     *  @see User#showUser(User)
     *  @see Post#showPost(Post)
     */
    void chooseOne(vector<Result>, std::function<void(Result)>);
};

#endif