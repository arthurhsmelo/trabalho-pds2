#ifndef POSTDAO_H
#define POSTDAO_H
#include <iostream>
#include "daos/DAO.hpp"
#include "models/User.hpp"
#include "models/Post.hpp"
#include <vector>

using namespace std;

class PostDAO : public DAO {

    public:
        /*
        *  Insere um post na tabela passado pelo model        
        */
        void insertPost(Post);
        /*
        *  Deleta um post passado pelo model         
        */
        void deletePost(Post);
        /*
        *  Altera QtLikes, QtReposts, QtReplies de um post passado pelo model         
        */
        void updatePost(Post);
        /*
        *  Altera o estado de um post passado pelo model         
        */
        vector<Post> selectFeed();
        /*
        *  Altera o estado de um post passado pelo model         
        *
        *  @param Recebe um usuário para pesquisar os posts que ele fez
        * 
        *  @return retorna o numero de posts desse usuario
        */
        int returnQtdUserPost(User);
        /*
        *  Acessa o nome da tabela da classe         
        *
        *  @return retorna o nome da tabela da classe
        */
        string getTableName();
        /*
        * Acessa a chave primeira da tabela da classe em questao
        * 
        *  @return retorna a chave primaria dessa tabela
        */
        string getPrimaryKey();   
};
#endif
