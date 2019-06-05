#include "views/PostScreen.hpp"
#include "models/Post.hpp"
#include <string>
#include <vector>
#include "models/Search.hpp"

using namespace std;

void PostScreen::printPost(int i, Post post){
    //if(post.getIsReply()){
        
    //}
    if(post.getIsRepost()){
        cout  << " ID:  [ " << i << " ] Repostado por: "+post.getUser().getUserName()+"" << endl;
        
    }else{
        cout  << " ID:  [ " << i << " ] Postado por: "+post.getUser().getUserName()+"" << endl;
    }
    cout << "-----------------------------" << endl;
        cout << post.getContent() << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "  Lks " << post.getQtLikes();
        cout << "  | Comp " << post.getQtReposts();
        cout << " | Coment " << post.getQtReplies() << endl;
        cout << "-----------------------------" << endl;  
}

void PostScreen::showMenu() {

    int choice = 0;

    do{
      

        Search search;
        vector<Post> feed = search.criaFeed();
        int i = 0, size = feed.size();

        cout << endl << "Feed" << endl;
        cout << "1 - Visualizar Post" << endl;
        cout << "2 - Criar Post" << endl;
        cout << "3 - Recarregar feed" << endl;
        cout << "4 - Voltar" << endl;

        if(size > 0) {
            for(i = 0; size > i; i++){
                printPost(i, feed[i]);
            }
        }
        
        cout << "Escolha uma das opcoes:";

        choice = this->getInput();

        switch(choice){
            case 1:
                this->postChoice();
                break;
            case 2:
                this->newPost();
                break;
            case 3:
                feed = search.criaFeed();
                break;
            case 4:
                break;
        }

    }while(choice != 4);
}

void PostScreen::postChoice(){

    Search search;
    vector<Post> feed = search.criaFeed();
    int size = feed.size(), choice = 0, i = 0;
    bool redirect = true;

    this->clrscr();
    cout << "Escreva o número do post a ser visualizado!" << endl;

        
    if(size > 0) {
        for(i = 0; size > i; i++){
            printPost(i, feed[i]);
        }
    }


    do {
        redirect = false;
        cout << "Escolha o id de um post:" << endl;
        
        choice = this->getInput();
        try{
            Post option = feed.at(choice);
            this->postOptions(option);
        } catch(const out_of_range& oor) {
            cout << "Post não encontrado!" << endl;
            
            redirect = true;
        }
    } while(redirect);
}

void PostScreen::newPost(){
    Post newPost;
     
    
    string data;

    this->clrscr();

    cout << "Crie seu post!" << endl;
    cout << "Digite seu post, conteudo vazio para cancelar a postagem" << endl;
    getline(cin, data);
    if(data.length() > 0) {
        newPost.setContent(data);
        newPost.setIsReply(false);
        newPost.setIsRepost(false);
        newPost.createPost();     
    }
}

void PostScreen::postOptions(Post post){

        int choice = 0;

        this->clrscr();
        cout << post.getContent() << endl;

        cout << "1 - Curtir" << endl;
        cout << "2 - Repostar" << endl;
        cout << "3 - Comentar" << endl;
        cout << "4 - Voltar" << endl;
        
        choice = this->getInput();
        Post newPost;

        switch(choice){
            case 1:
                post.setQtLikes(post.getQtLikes() + 1);
                post.updatePost();
                break;
            case 2:
                post.setQtReposts(post.getQtReposts()+1);
                post.updatePost();
                newPost = post;
                newPost.setIsRepost(true);
                newPost.createPost();
                break; 
            case 3:
                this->postComment(post);
                break;
            case 4:
                break;
            default:
                cout << "Digite um numero valido!" << endl;
                break;
        }
}

void PostScreen::postComment(Post post){
     
    int choice = 0;
    string data;

    do{
        this->clrscr();

        cout << "Escreva seu comentário!" << endl;
        cout << "1 - Cancelar" << endl;
        cout << "Digite seu comentário:" << endl;

        getline(cin, data);

        if(data.length() <= 0){
            cout << "Digite um conteúdo para seu comentário!" << endl;
        }else{
            break;
        }
    }while(choice != 1);

    post.setQtReplies(post.getQtReplies() + 1);
    post.updatePost();
    post.setContent(data);
    post.setIsReply(true);
    post.setIsRepost(false);
    post.createPost();

}

void PostScreen::showPost(Post post){
    cout << post.getContent() << endl;
    cout << "  Lks " << post.getQtLikes();
    cout << "   Comp " << post.getQtReposts();
    cout << "  Coment " << post.getQtReplies() << endl; 
}
