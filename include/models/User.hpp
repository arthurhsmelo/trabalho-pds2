#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

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
        vector<User> _followings;
        vector<User> _followers;
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
        void setFollowings(User);
        vector<User> getFollowings();        
        vector<User> getFollowers();
        /* End Get and Set*/

        /**
         *  Checar se o usuário logado está seguindo outro usuário.
         *  
         *  @param User usuario a ser verificado se é seguido.
         * 
         *  @return bool vetor de objetos User encontrados.
         */
        bool checkIsFollowing(User);        


        /**
         *  Usuário logado deixar de seguir um usuário escolhido
         *  
         *  @param User usuario que deixará de ser seguido pelo usuário logado.
         *          
         */
        void unfollow(User);
};

#endif