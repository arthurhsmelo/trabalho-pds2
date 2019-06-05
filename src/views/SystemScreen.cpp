#include "views/SystemScreen.hpp"

void SystemScreen::showMenu() {
    System *session = System::getInstance();

    int choice = 0;
    do {
        this->clrscr();

        cout << "Login / Cadastro" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "1 - Logar" << endl;
        cout << "2 - Cadastrar" << endl;
        cout << "Escolha: ";
        
        choice = this->getInput();
        
        switch(choice) {
            case 1:
                this->requestLogin();
                break;
            case 2:
                this->requestSignup(true);
                break;
            default:
                break;
        }

    } while(session->getLoggedUser() == nullptr); 

    MainScreen::showMenu();
}

void SystemScreen::requestLogin() {
    System *session = System::getInstance();
    this->clrscr();
    
    string username, password, choice;
    bool repeat = true;

    cout << "Login" << endl;

    cout << "Digite seu usuário:" << endl;
    std::cin >> username;
    
    cout << "Digite sua senha:" << endl;
    std::cin >> password;
        
    cout << "Logando..." << endl;

    do {
        try {
            session->login(username, password);
            repeat = false;

        } catch(Exception::InvalidPassword& e) {
            cout << "Senha inválida!" << endl;    
            cout << "Digite sua senha:" << endl;
            std::cin >> password;
                
            cout << "Logando..." << endl;

        } catch(Exception::UserNotFound& e) {
            cout << "Usuário não encontrado!" << endl;    
            cout << "Deseja se cadastrar? (S/N)" << endl;
            std::cin >> choice;

            if(choice.compare("S") == 0 || choice.compare("s") == 0) {
                repeat = false;
                this->requestSignup(true);
            } else {
                repeat = false;
                this->requestLogin();
            }     
        }
    } while(repeat);
}

void SystemScreen::requestSignup(bool reload) {
    System *session = System::getInstance();
    this->clrscr();

    string username, password, name;
    bool repeat = true;

    cout << "Cadastro" << endl;

    cout << "Digite seu usuário:" << endl;
    std::cin >> username;

    cout << "Digite seu nome:" << endl;
    std::cin >> name;
    
    cout << "Digite sua senha:" << endl;
    std::cin >> password;
        
    cout << "Cadastrando..." << endl;

    do {
        try {
            session->signup(name, username, password, reload);
            repeat = false;

        } catch(Exception::UserAlreadyExists& e) {
            cout << "Usuário já existe!" << endl;    
            cout << "Digite seu usuário:" << endl;
            std::cin >> username;
                
            cout << "Cadastrando..." << endl;    
        }
    } while(repeat);
}

void SystemScreen::requestLogout() {
    System *session = System::getInstance();
    this->clrscr();

    string choice;

    cout << "Deseja realmente sair?" << endl;
    std::cin >> choice;

    if(choice.compare("S") == 0 || choice.compare("s") == 0) {
        cout << "Saindo..." << endl;
        session->logout();
    } 

    MainScreen::showMenu();            
}

void SystemScreen::requestSignout() {
    System *session = System::getInstance();
    this->clrscr();

    string choice;

    cout << "Deseja realmente apagar a conta: @" << session->getLoggedUser()->getName() << " ?" << endl;
    std::cin >> choice;

    if(choice.compare("S") == 0 || choice.compare("s") == 0) {
        cout << "Apagando..." << endl;
        session->signout();
    } 

    MainScreen::showMenu();   
}
