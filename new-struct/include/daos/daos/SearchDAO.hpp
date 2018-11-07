#ifndef SEARCHDAO_H
#define SEARCHDAO_H

#include "daos/DAO.hpp"

class SearchDAO : public DAO {
    public:
        string getTableName();
        string getPrimaryKey();

};

#endif