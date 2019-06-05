#include <iostream>
#include "daos/daos/PostDAO.hpp"
#include "models/Search.hpp"
#include "models/Post.hpp"
#include "models/User.hpp"
#include <vector>
#include <string>

using namespace std;

string PostDAO::getPrimaryKey() {
    return "post_id";
};
string PostDAO::getTableName() {
    return "post";
};

void PostDAO::insertPost(Post post){

    System *session = System::getInstance();
    User* user = session->getLoggedUser();

    string query  = "        INSERT INTO post (   ";
    query += "                    post_id, ";
    query += "                    user_id, ";
    query += "                    content, ";
    query += "                   qt_likes, ";
    query += "                 qt_replies, ";
    query += "                 qt_reposts, ";
    query += "                   is_reply, ";
    query += "                  is_repost) ";
    query += "                     VALUES (";
    query +=         this->getNextId() +", ";
    query +=          user->getId() + ",'  ";
    query +=      post.getContent() + " ', ";
    query +=                            "0,";
    query +=                            "0,";
    query +=                            "0,";
    query +=       to_string(post.getIsReply()) + ", ";
    query +=      to_string(post.getIsRepost()) + ") ";
    
    this->insert(query);
} 

void PostDAO::deletePost(Post post){
    
    string query = "";

    query = "DELETE * FROM post WHERE id = "+to_string(post.getId())+";";

    this->remove(query);
}

void PostDAO::updatePost(Post post){
    
    string query = "";

    query =  "  UPDATE post SET                                              ";
    query += "                  post_id = '"+ to_string(post.getId()) + "',    ";
    query += "                  content = '"+ post.getContent() +"',           ";
    query += "                  qt_likes = '"+to_string(post.getQtLikes())+"', ";
    query += "              qt_replies = '"+to_string(post.getQtReplies())+"', ";
    query += "              qt_reposts = '"+to_string(post.getQtReposts())+"', ";
     query += "              is_reply = '"+to_string(post.getIsReply())+"',    ";
    query += "              is_repost = '"+to_string(post.getIsRepost())+"'   ";
    query += "  WHERE post_id = '"+to_string(post.getId())+"';"                 ; 

    this->update(query);
}

vector<Post> PostDAO::selectFeed(){
    
    System *session = System::getInstance();
    User* user = session->getLoggedUser();
    string userId = user->getId();
    string idFollow = "";
    vector<map<string, string>> select;
    vector<Post> feed;
    vector<User> following = user->getFollowings();
    int size = following.size();


    for(int i = 0; size > i; i++){
        if(i == (size - 1)){
            idFollow.append("'"+following[i].getId()+"' ");
        }else{
            idFollow.append("'"+following[i].getId()+"', ");
        }
    }
    

    string query = "";
    
    query =  "SELECT * FROM post ";
    query += "WHERE user_id in ("+idFollow+") or user_id = '"+userId+"' and is_reply = '0' ";
    query += "ORDER BY post_id DESC;";


    select = this->select(query);

    if(select.size() > 0){   
        for(auto objPost: select){
            Post post;
            UserDAO search;
            User* usuarioPost;

            usuarioPost = search.selectUserById(objPost["user_id"]);
            
            post.setUser(*usuarioPost);
            post.setId(stoi(objPost["post_id"]));
            post.setIsReply(stoi(objPost["is_reply"]));
            post.setIsRepost(stoi(objPost["is_repost"]));
            post.setContent(objPost["content"]);
            post.setQtLikes(stoi(objPost["qt_likes"]));
            post.setQtReplies(stoi(objPost["qt_replies"]));
            post.setQtReposts(stoi(objPost["qt_reposts"]));
            
            feed.push_back(post);
        }
    }

    return feed;
}

int PostDAO::returnQtdUserPost(User user){

	int quantidadePost;
	vector<map<string, string>> select;

	string query = "";

	query = "SELECT count(*) quantidadePost FROM post WHERE user_id = "+user.getId()+";";

	select = this->select(query);

	quantidadePost = stoi(select[0]["quantidadePost"]);

	return quantidadePost;

}

/*vector<Post> selectUserPosts(int userId){
   
    vector<map<string, string>> UserPosts;
    string query = "";

    query =  "  SELECT content FROM Post                ";
    query += "    WHERE userId = "+to_string(userId)+"; ";

    UserPosts = this->select(query);
    return UserPosts;
}*/
