#ifndef USERDAO_H
#define USERDAO_H

#include "daos/DAO.hpp"
#include "models/User.hpp"

class UserDAO : public DAO {
    public:
        /*
         *  Busca Nome da Tabela         
         *           
         * 
         *  @return string nome da tabela.
        */
        string getTableName();

        /*
         *  Busca nome da chave primaria da tabela         
         *           
         * 
         *  @return string nome da chave primaria da tabela.
        */
        string getPrimaryKey();    

        /*
         *  Busca um usuario pelo seu username         
         * 
         *  @return User objeto usuário retornado.
        */
        User* select(string);

        /*
         *  Busca um usuario pelo seu username e password     
         * 
         *  @return User objeto usuário retornado.
        */
        User* select(string, string);        

        /*
         *  Insere um usuario no BD
         * 
         * *  @param User usuário a ser inserido.
         *          
        */
        void insert(User);

        /*
         *  Remove um usuario no BD
         * 
         * *  @param User usuário a ser removido.
         *          
        */
        void remove(User*);

        /*
         *  Insere um usuario que seguira outro usuario
         * 
         * *  @param User usuário que seguirá
         *    @param User usuário que será seguido.
         *          
        */
        void insertFollow(User, User);

        /*
         *  Remove um usuario que deixará de seguir outro usuario
         * 
         * *  @param User usuário que não seguirá
         *    @param User usuário que não será seguido.
         *          
        */
        void removeFollow(User*);   
        void removeFollow(User, User);

        /*
         *  Remove um usuario que deixará de seguir outro usuario
         * 
         * *  @param User usuário que não seguirá
         *    @param bool verificar se é para retornar os seguidores ou as pessoas que seguem o usuario
         * *  @return vector<User> vetor de usuarios
         *          
        */
        vector<User> selectFollow(User, bool);
        /*
         *  Retorna um usuario pelo id
         * 
         * *  @param Id do usuario
         * *  @return Retorna um usuario
         *          
        */
        User* selectUserById(string);
};

#endif