#include "views/UserScreen.hpp"

void UserScreen::showMenu() {

    try{

        System *session = System::getInstance();
        User* user = session->getLoggedUser();
        
        if(user == nullptr)
            throw Exception::UserNotFound();
        
        int choice = 0;
        this->clrscr();
        do {            
            
            this->showUser(*user);
            cout << "Perfil" << endl;
            cout << "Escolha uma opção" << endl;
            cout << "1 - Visualizar outro perfil" << endl;
            cout << "2 - Visualizar usuários que você segue" << endl;
            cout << "3 - Visualizar seguidores" << endl;
            cout << "4 - Voltar" << endl;
            cout << "Escolha: ";
            
            choice = this->getInput();
            
            switch(choice) {
                case 1:
                    showAnotherUser();
                    break;
                case 2:
                    showFollow(*user, true);                    
                    break;
                case 3:
                    showFollow(*user, false);
                    break;
                default:                    
                    break;
            }
        } while(choice != 4);    

    } catch(Exception::UserNotFound& e) {
        cout << "Usuário não encontrado!" << endl; 
    } catch(std::exception& e) {
        cout << e.what() << endl; 
    }  
}

void UserScreen::showUser(User user){
    cout << "\n" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "--------------------------- Usuário ------------------------------------" << endl;    
    cout << "Nome: " + user.getName() << endl;
    cout << "Login: " + user.getUserName() << endl;
    cout << "Quantidade de Posts: " + getQtPosts(user) << endl;
    cout << "Seguindo: " + user.getQtFollowing() << endl;
    cout << "Seguidores: " + user.getQtFollowers() << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "\n" << endl;

    //Verificar se o usuario já segue o usuario do perfil escolhido
    checkFollow(user);
}

void UserScreen::showAnotherUser() {  
    try {     
        SearchScreen searchScreen;
        searchScreen.showOptionUser();    
    } catch(std::exception& e) {
        cout << e.what() << endl; 
    }
}

void UserScreen::showFollow(User user, bool isFollowing) {      

    try {
        this->clrscr();     

        string texto = isFollowing ? "Seguindo" : "Seguidores";    

        vector<User> usersVector = isFollowing ? user.getFollowings() : user.getFollowers();
        cout << "\n" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "--------------------------- " + texto + " ------------------------------" << endl;            

        if(usersVector.size() > 0) 
            for (auto objUser: usersVector)
                cout << objUser.getUserName() << endl;        
        
        cout << "------------------------------------------------------------------------" << endl;
        cout << "\n" << endl; 
    } catch(std::exception& e) {
        cout << e.what() << endl; 
    }
}

void UserScreen::checkFollow(User user){

    try {

        System *session = System::getInstance();
        User* loggedUser = session->getLoggedUser();

        if(loggedUser == nullptr)
            throw Exception::UserNotFound();

        if(loggedUser->getUserName() != user.getUserName()) {
            bool isFollowing = loggedUser->checkIsFollowing(user);
            string msg = loggedUser->getName() + ". ";
            msg += (isFollowing ? "Deseja parar de seguir " : "Deseja seguir ") + user.getName() + "?";       
        
            cout << msg << endl;
            cout << "1 - Sim" << endl;
            cout << "2 - Não" << endl;
            cout << "Escolha: ";
            
            int choice = this->getInput();
            
            switch(choice) {
                case 1:                
                    if(isFollowing) loggedUser->unfollow(user); else loggedUser->setFollowings(user);
                    break;
                default:
                    cin.clear();
                    break;
            }        
        }

    } catch(Exception::UserNotFound& e) {
        cout << "Usuário não encontrado!" << endl; 
    } catch(std::exception& e) {
        cout << e.what() << endl; 
    }   
} 

string UserScreen::getQtPosts(User user){
    PostDAO postDao;
    return to_string(postDao.returnQtdUserPost(user));
}