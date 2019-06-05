#include "views/SearchScreen.hpp"

void showUser(User user) {
    UserScreen screen;
    screen.showUser(user);
}

void showPost(Post post) {
    PostScreen screen;
    screen.showPost(post);
}

template <class Result>
void SearchScreen::chooseOne(vector<Result> list, std::function<void(Result)> callback) {
    int choice = 0;
    bool redirect;

    do {
        redirect = false;
        cout << "Escolha um dos resultados: "  << endl;
        
        choice = this->getInput();
        try{
            Result option = list.at((choice - 1));
            callback(option);
        } catch(const out_of_range& oor) {
            cout << "Resultado não encontrado!" << endl;
            
            redirect = true;
        }
    } while(redirect);

}

void SearchScreen::searchUsers(string searchContent) {
    int selectorId = 1;
    Search search;
    vector<User> usersReturned = search.searchUsers(searchContent);

    if(usersReturned.size() > 0) {
        cout << endl;
        cout << " ------------------------------------ " << endl;
        cout << " ----- Usuário(s) Encontrado(s) ----- " << endl;
        cout << " ------------------------------------ " << endl;
        for(auto user : usersReturned) {
            cout << " -- " << selectorId << " -- @" << user.getUserName() << endl;
            selectorId++;
        }
        cout << " ------------------------------------ " << endl << endl;

        std::function<void(User)> showUserF = &showUser;
        this->chooseOne(usersReturned, showUserF);

    } else {
        cout << endl << "Nenhum usuário encontrado!" << endl << endl;
    }
}

void SearchScreen::searchPosts(string searchContent) {
    int selectorId = 1;
    Search search;
    vector<Post> postsReturned = search.searchPosts(searchContent);

    if(postsReturned.size() > 0) {
        cout << endl;
        cout << " ------------------------------------ " << endl;
        cout << " ----- Post(s) Encontrado(s) -------- " << endl;
        cout << " ------------------------------------ " << endl;
        for(auto post : postsReturned) {
            cout << " -- " << selectorId << " -- @" << post.getUser().getUserName() << endl;
            cout << " -- " << post.getContent().substr(0,20) << endl;
            cout << " ------------------------------------" << endl;
            selectorId++;
        }
        cout << endl;

        std::function<void(Post)> showPostF = &showPost;
        this->chooseOne(postsReturned, showPostF);

    } else {
        cout << endl << "Nenhum post encontrado!" << endl;
    }   
}

void SearchScreen::showMenu() {
    this->clrscr();
    int choice = 0;
    string searchContent;
    do {
        cout << "Pesquisar" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "1 - Um usuário" << endl;
        cout << "2 - Um post" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha: ";
        
        choice = this->getInput();
        
        switch(choice) {
            case 1:                
                this->showOptionUser();
                break;
            case 2:
                this->clrscr();
                cout << "Qual o conteúdo do post que você deseja buscar?" << endl;
                cin >> searchContent;
                this->searchPosts(searchContent);
                break;
            default:
                cin.clear();
                break;
        }
    } while(choice != 3);    
}

void SearchScreen::showOptionUser(){ 
    this->clrscr();
    string searchContent;       
    cout << "Qual username você deseja buscar?" << endl;
    cin >> searchContent;
    this->searchUsers(searchContent);
}