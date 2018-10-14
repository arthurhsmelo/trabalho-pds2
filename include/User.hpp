#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include "Post.hpp"

namespace User {
    class User {
        private:
            int id;
            std::string name;
            std::string password;
            std::string userName;
            int qtPosts;
            int qtLikes;
            int qtFollowing;
            int qtFollowers;

        public:  
            /* Getters and Setters */
            void setId(int);
            int getId();
            void setName(std::string);
            std::string getName();
            void setPassword(std::string);
            std::string getPassword();
            void setUserName(std::string);
            std::string getUserName();
            void setQtPosts(int);
            int getQtPosts();
            void setQtLikes(int);
            int getQtLikes();
            void setQtFollowing(int);
            int getQtFollowing();
            void setQtFollowers(int);
            int getQtFollowers();
            /* End Get and Set*/

            /**
             * Login and Logout          
             * @params:  std::string username
             *           std::string password
             *           int    systemId
             * 
             * @return:
             *           bool   true if was a successful operation 
             **/
            bool doLogin(std::string, std::string, int);
            bool doLogout(std::string, int);
            
            /**
             * Post and Repost          
             * @params:  std::string content
             *           int    postId
             *           std::string repostContent
             * 
             * @return:
             *           int    postId
             **/
            int post(std::string);
            int rePost(int);
            int rePost(int, std::string);
            
            /**
             * Comment          
             * @params:  int    postId
             *           std::string comment
             * 
             * @return:
             *           bool   true if was a successful operation 
             **/
            bool comment(int, std::string);
            
            /**
             * Search          
             * @params:  std::string userName
             *           std::string postContent
             * 
             * @return:
             *           std::vector<User/Post> list of matched results
             **/
            std::vector<User> searchUsers(std::string);
            std::vector<Post::Post> searchPost(std::string);
            
            /**
             * Follow and Unfollow          
             * @params:  int    userId - obs.: the User who's going to be followed/unfollowed - 
             * 
             * @return:
             *           bool   true if was a successful operation 
             **/
            bool follow(int);
            bool unfollow(int);
            
            /**
             * Message          
             * @params:  int    recipientId - obs.: the User who's going to receive the message - 
             *           std::string content             
             * 
             * @return:
             *           bool   true if was a successful operation 
             **/
            bool sendMessage(int, std::string);
            
            /**
             * Message          
             * @params:  int    userId - obs.: the User who's going to have the profile shown - 
             * 
             * @return:
             *           User   user matched
             **/
            User showProfile(int);

    };
}

#endif