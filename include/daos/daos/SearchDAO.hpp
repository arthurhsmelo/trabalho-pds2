#ifndef SEARCHDAO_H
#define SEARCHDAO_H

#include <string>
#include "daos/DAO.hpp"
#include "daos/daos/UserDAO.hpp"
#include "models/Post.hpp"
#include "models/User.hpp"

using std::string;

/**
 *  Data Access Object responsável pelas buscas. 
 *  Busca Usuários e Posts no sistema pelo username ou pelo conteúdo do post.
 *  @see DAO#select(string)
 */
class SearchDAO : public DAO {
    public:
        /**
         *  Busca Posts.
         *  Comunica com o banco, buscando posts que tem conteúdo parecido com o passado como parâmetro.
         *  
         *  @param string contúdo a ser buscado.
         * 
         *  @return vector<Post> vetor de objetos Post encontrados.
         */
        vector<Post> searchPosts(string);

        /**
         *  Busca Usuários.
         *  Comunica com o banco, buscando usuários que tem username parecido com o passado como parâmetro.
         *  
         *  @param string username a ser buscado.
         * 
         *  @return vector<User> vetor de objetos User encontrados.
         */
        vector<User> searchUsers(string);

};

#endif