#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;

class User {
    private:
        string _id;
        string _name;
        string _password;
        string _userName;
        string _systemId;
        string _qtPosts;
        string _qtLikes;
        string _qtFollowing;
        string _qtFollowers;
    public:
        /* Getters and Setters */
        User();
        User(string, string, string);
        void setId(string);
        string getId();
        void setName(string);
        string getName();
        void setPassword(string);
        string getPassword();
        void setUserName(string);
        string getUserName();
        void setSystemId(string);
        string getSystemId();
        void setQtPosts(string);
        string getQtPosts();
        void setQtLikes(string);
        string getQtLikes();
        void setQtFollowing(string);
        string getQtFollowing();
        void setQtFollowers(string);
        string getQtFollowers();
        /* End Get and Set*/
};

#endif