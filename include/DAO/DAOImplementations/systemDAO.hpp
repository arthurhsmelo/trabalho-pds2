#ifndef SYSTEMDAO_H
#define SYSTEMDAO_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 

using std::string;
using std::map;
using std::vector;

class SystemDAO { 
    
    public:	
        void createSystemTable();
        void createUserTable();
        void createPostTable();
        void createMessageTable();
};

#endif