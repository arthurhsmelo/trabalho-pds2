#ifndef USERDAO_H
#define USERDAO_H

#include "daos/DAO.hpp"
#include "models/User.hpp"

class UserDAO : public DAO {
    public:
        string getTableName();
        string getPrimaryKey();
        User* select(string);
         User* select(string, string);
        vector<User> selectList();
        void insert(User*);
        void remove(User*);

};

#endif