#ifndef MESSAGEDAO_H
#define MESSAGEDAO_H

#include "daos/DAO.hpp"

class MessageDAO : public DAO {
    public:
        string getTableName();
        string getPrimaryKey();
};

#endif