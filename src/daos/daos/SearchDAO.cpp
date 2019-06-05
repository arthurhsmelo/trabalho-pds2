#include "daos/daos/SearchDAO.hpp"

vector<Post> SearchDAO::searchPosts(string content) {
    vector<Post> postsFound;
    string query = "SELECT * FROM POST WHERE CONTENT LIKE('%" + content + "%')";

    vector<map<string, string>> postsVector = this->select(query);

    if(postsVector.size() > 0) {
        for (auto objPost: postsVector){
            Post post;
            UserDAO search;
            User* usuarioPost;

            usuarioPost = search.selectUserById(objPost["user_id"]);
            post.setId(stoi(objPost.find("post_id")->second));        
            post.setContent(objPost.find("content")->second);
            post.setUser(*usuarioPost);
            post.setQtLikes(stoi(objPost.find("qt_likes")->second));
            post.setQtReposts(stoi(objPost.find("qt_reposts")->second));
            post.setQtReplies(stoi(objPost.find("qt_replies")->second));
            post.setIsReply(stoi(objPost.find("is_reply")->second));
            post.setIsRepost(stoi(objPost.find("is_repost")->second));
            postsFound.push_back(post);
        }
    }
    return postsFound;
}
vector<User> SearchDAO::searchUsers(string username) {
    vector<User> usersFound;
    string query = "SELECT * FROM USER WHERE USERNAME LIKE('%" + username + "%')";

    vector<map<string, string>> usersVector = this->select(query);

    if(usersVector.size() > 0) {
        for (auto objUser: usersVector){
            User user;
            user.setId(objUser.find("user_id")->second);        
            user.setName(objUser.find("name")->second);
            user.setPassword(objUser.find("password")->second);
            user.setUserName(objUser.find("username")->second);
            user.setSystemId(objUser.find("system_id")->second);
            user.setQtPosts(objUser.find("qt_posts")->second);
            user.setQtLikes(objUser.find("qt_likes")->second);
            user.setQtFollowing(objUser.find("qt_following")->second); 
            user.setQtFollowers(objUser.find("qt_followers")->second);        
            usersFound.push_back(user);
        }
    }
    return usersFound;    
}