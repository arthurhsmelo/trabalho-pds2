#ifndef POST_H
#define POST_H

#include "models/User.hpp"

#include <string>
class Post {
    private:
        int _id;
        User user;
        std::string _content;
        int _qtLikes;
        int _qtReplies;
        int _qtReposts;
        bool _isReply;
        bool _isRepost;


    public:  
        Post();
        /* Getters and Setters */
        void setId(int);
        int getId();
        void setContent(std::string);
        std::string getContent();
        void setQtLikes(int);
        int getQtLikes();
        void setQtReplies(int);
        int getQtReplies();
        void setQtReposts(int);
        int getQtReposts();
        void setIsReply(bool);
        bool getIsReply();
        void setIsRepost(bool);
        bool getIsRepost();
        void setUser(User);
        User getUser();
        /* End Get and Set*/

        /**
        *  Chama a DAO para criar um post
        *  
        *  @param Atributos iniciais de criação de um post
        */
        void createPost();
        /**
        *  Atualiza QtLikes, QtReposts, QtReplies de um post
        *  
        *  @param Atributos a serem alterados e o post_id
        */
        void updatePost();
        /**
        *  Deleta um post
        *  
        *  @param post_id do post a ser deletado
        */
        void deletePost();

};


#endif
