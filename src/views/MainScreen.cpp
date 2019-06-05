#include "views/MainScreen.hpp"
#include "views/SystemScreen.hpp"
#include "views/SearchScreen.hpp"
#include "views/PostScreen.hpp"
#include "views/UserScreen.hpp"
#include "views/MessageScreen.hpp"
#include "exceptions/Exception.hpp"

MainScreen::~MainScreen() {
}

void MainScreen::clrscr() {
    cout << "\x1B[2J\x1B[H";
}

int MainScreen::getInput() {
    int choice = 0;
    bool repeat = true;
    do {
        try {
            if(!(cin >> choice)) {
                throw Exception::InvalidInput();    
            } else {
                repeat = false;
            }
        } catch(Exception::InvalidInput& e) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Entrada inválida.  Tente novamente: ";
        }
    } while(repeat);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // eat next newline 
    return choice;      
} 

void MainScreen::showConfigOptions() {
    int choice = 0;
    SystemScreen sScreen;
    do {
        this->clrscr();
        cout << "Configurações" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "1 - Logout" << endl;
        cout << "2 - Apagar conta" << endl;
        cout << "3 - Cadastrar uma nova conta" << endl;
        cout << "4 - Voltar" << endl;
        cout << "Escolha: ";
        
        choice = this->getInput();
        switch(choice) {
            case 1:
                sScreen.requestLogout();
                break;
            case 2:
                sScreen.requestSignout();
                break;
            case 3:                     
                sScreen.requestSignup(false);
                break;
            default:
                break;
        }
    } while(choice!=4);
}

void MainScreen::showMenu() {
    try {
        PostScreen pScreen;
        UserScreen uScreen;   
        SearchScreen shScreen;
        MessageScreen mScreen;
        
        System *session = System::getInstance();
        if(session->getLoggedUser() != nullptr) {
            int choice = 0;
            do {
                this->clrscr();
                cout << "Menu Principal" << endl;
                cout << "Escolha uma opção" << endl;
                cout << "1 - Ver meu feed" << endl;
                cout << "2 - Ver meu perfil" << endl;
                cout << "3 - Pesquisar" << endl;
                cout << "4 - Ver minhas conversas" << endl;
                cout << "5 - Configurações" << endl;
                cout << "6 - Sair" << endl;
                cout << "Escolha: ";
                
                choice = this->getInput();
                
                switch(choice) {
                    case 1:
                        pScreen.showMenu();
                        break;
                    case 2:
                        uScreen.showMenu();
                        break;
                    case 3:                     
                        shScreen.showMenu();
                        break;
                    case 4:
                        mScreen.showMenu();
                        break;
                    case 5:
                        this->showConfigOptions();
                        break;
                    case 6:
                        cout << "Saindo..." << endl;
                        if(session)
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


