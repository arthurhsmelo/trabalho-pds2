#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User {
public:
    User(string, string, string);
    string getName();
};

#endif