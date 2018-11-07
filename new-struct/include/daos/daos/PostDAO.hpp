#ifndef POSTDAO_H
#define POSTDAO_H

#include "daos/DAO.hpp"

class PostDAO : public DAO {
    public:
        string getTableName();
        string getPrimaryKey();

};

#endif