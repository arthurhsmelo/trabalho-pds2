#include "models/Search.hpp"

vector<User>  Search::searchUsers(string username) {
    SearchDAO searchDao;
    vector<User> users = searchDao.searchUsers(username);
    return users;
}

vector<Post>  Search::searchPosts(string content) {
    SearchDAO searchDao;
    vector<Post> posts = searchDao.searchPosts(content);
    return posts;
}

vector<Message> Search::selectConversation(string locutorUser, string interlocutorUser){
    MessageDAO messageDAO;
    vector<Message> messages = messageDAO.selectConversation(locutorUser, interlocutorUser);
    return messages;
}

vector<Message> Search::selectFiveLastMessages(){
    MessageDAO messageDAO;
    System *session = System::getInstance();
    vector<Message> messages = messageDAO.selectFiveLastMessages(session->getLoggedUser()->getUserName());
    return messages;
}

vector<Post> Search::criaFeed(){
    
    vector<Post> feed;
    PostDAO postDAO;

    feed = postDAO.selectFeed();

    return feed;
}

int Search::returnQtdUserPost(User user){

    int quantidadePost;
    PostDAO postDAO;
    quantidadePost = postDAO.returnQtdUserPost(user);

    return quantidadePost;
}
