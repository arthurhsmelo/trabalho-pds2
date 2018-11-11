#include "views/MainScreen.hpp"
#include "views/SystemScreen.hpp"
#include "views/SearchScreen.hpp"
#include "views/PostScreen.hpp"
#include "views/UserScreen.hpp"
#include "views/MessageScreen.hpp"

MainScreen::~MainScreen() {

}

void MainScreen::clrscr() {
    cout << "\x1B[2J\x1B[H";
}

int MainScreen::getInput() {
    int choice;    
    std::cin >> choice;
    return choice;
} 

void MainScreen::showMenu() {
    try {
        System *session = System::getInstance();
        if(session->getLoggedUser() != nullptr) {
            int choice = 0;
            do {
                this->clrscr();
                cout << "Menu Principal" << endl;
                cout << "Escolha uma opção" << endl;
                cout << "1 - Ver meu feed" << endl;
                cout << "2 - Buscar um post ou usuário" << endl;
                cout << "3 - Ver meu perfil" << endl;
                cout << "4 - Ver minhas mensagens" << endl;
                cout << "5 - Configurações" << endl;
                cout << "6 - Sair" << endl;
                cout << "Escolha: ";
                
                choice = this->getInput();
                
                switch(choice) {
                    case 1:
                        cout << "Feed!" << endl;
                        break;
                    case 2:
                        cout << "Busca!" << endl;
                        break;
                    case 3:
                        cout << "Perfil!" << endl;
                        break;
                    case 4:
                        cout << "Mensagens!" << endl;
                        break;
                    case 5:
                        //showConfigOptions();
                        break;
                    case 6:
                        cout << "Saindo..." << endl;
                        delete session;
                        break;
                    default:
                        break;
                }

            } while(choice!=6);
        } else {
            SystemScreen sScreen;
            sScreen.showMenu();
        }
    } catch(Exception::BadDataBaseInitialization& e) {
        cout << "Erro na inicialização do banco de dados." << endl << "Fechando...";
    }

}