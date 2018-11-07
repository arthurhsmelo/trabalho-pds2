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

class SystemDAO : public DAO { 
public:	
    bool createUserTable();
    bool createPostTable();
    bool createMessageTable();
    string getTableName();
    string getPrimaryKey();
};

#endif