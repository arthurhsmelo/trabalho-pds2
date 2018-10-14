#ifndef POST_H
#define POST_H


#include <string>

namespace Post {
    class Post {
        private:
            int id;
            int userId;
            std::string content;
            int qtLikes;
            int qtReplies;
            int qtReposts;
            bool isReply;
            bool isRepost;

        public:  
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
            /* End Get and Set*/

    };
}


#endif