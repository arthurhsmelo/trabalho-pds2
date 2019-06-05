#ifndef SYSTEMDAO_H
#define SYSTEMDAO_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include "daos/DAO.hpp"

using std::string;
using std::map;
using std::vector;

/**
 *  Data Access Object responsável pela criação das tabelas do sistema. 
 *  @see DAO#createTable(string)
 */
class SystemDAO : public DAO { 
    public:	
        /**
         *  Cria a tabela user.
         *  
         *  @return bool booleano indicando se tudo ocorreu corretamente.
         */
        bool createUserTable();
        /**
         *  Cria a tabela post.
         *  
         *  @return bool booleano indicando se tudo ocorreu corretamente.
         */
        bool createPostTable();
        /**
         *  Cria a tabela message.
         *  
         *  @return bool booleano indicando se tudo ocorreu corretamente.
         */
        bool createMessageTable();
        /**
         *  Cria a tabela follow.
         *  
         *  @return bool booleano indicando se tudo ocorreu corretamente.
         */
        bool createFollowTable();
};

#endif