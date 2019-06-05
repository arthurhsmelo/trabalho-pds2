#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <vector>
#include "models/User.hpp"
#include "models/Post.hpp"
#include "daos/daos/SearchDAO.hpp"
#include "daos/daos/MessageDAO.hpp"
#include "models/Message.hpp"
#include "models/System.hpp"
#include "daos/daos/PostDAO.hpp"

using std::string;
using std::vector;

/**
 *  Comunica com o SearchDAO para buscar usuários e posts
 */
class Search {
    public:
        /**
         *  Busca Usuários.
         *  
         *  @param string username a ser buscado.
         * 
         *  @return vector<User> vetor de objetos User encontrados.
         */
        vector<User> searchUsers(string);
        /**
         *  Busca Posts.
         *  
         *  @param string contúdo a ser buscado.
         * 
         *  @return vector<Post> vetor de objetos Post encontrados.
         */
        vector<Post> searchPosts(string);
        /**
         *  Busca Mensagens da conversa selecionada.
         *  
         *  @param string usuário logado
         *  @param string outro usuário
         * 
         *  @return vector<Message> vetor de objetos Message encontrados nesta conversa.
         */
        vector<Message> selectConversation(string, string);
        /**
         *  Retorna as 5 últimas mensagens de conversas diferentes com o usuário logado.
         * 
         *  @return vector<Message> vetor de objetos Message encontrados.
         */
        vector<Message> selectFiveLastMessages(); 
        /**
         *  Cria um feed de posts.
         * 
         *  @return vector<Post> feed montado.
         */
        vector<Post> criaFeed();
        /**
         *  Retorna quantidade de posts de um usuario
         * 
         *  @return numero de posts.
         */
        int returnQtdUserPost(User);
};

#endif
