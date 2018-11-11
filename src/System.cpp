#include "System.hpp"

int getInput() {
    int choice;    
    std::cin >> choice;
    return choice;
}  

System::System() {
    this->initialize();
}

void showConfigOptions() {
    int choice = 0;
    do {
        system("cls");

        cout << "Configurações" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "1 - Sair" << endl;
        cout << "2 - Criar um usuário" << endl;
        cout << "Escolha: ";            

        choice = getInput();
        switch(choice) {
            case 1:
                cout << "Saiu!" << endl;
                break;
            case 2:
                cout << "Criar Usuário!" << endl;
                break;
            case 3:
                break;
            default:
                break;
        }
        
        system("PAUSE");
    } while(choice!=1);
}   

void System::showMenu() {
    int choice = 0;
    do {
        system("cls");

        cout << "Menu Principal" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "1 - Ver meu feed" << endl;
        cout << "2 - Buscar um post ou usuário" << endl;
        cout << "3 - Ver meu perfil" << endl;
        cout << "4 - Ver minhas mensagens" << endl;
        cout << "5 - Configurações" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha: ";
        
        choice = getInput();
        
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
                showConfigOptions();
                break;
            case 6:
                cout << "Saiu!" << endl;
                break;
            default:
                break;
        }

        system("PAUSE");
    } while(choice!=6);

}

bool System::initializeDB() {
    SystemDAO *systemDao = new SystemDAO();

    systemDao->createSystemTable();
    systemDao->createUserTable();
    systemDao->createPostTable();
    systemDao->createMessageTable();

    return true;
}

bool System::initialize() {
    cout << "Inicializando o Sistema..." << endl;

    cout << "Inicializando o Banco de Dados.." << endl;
    this->initializeDB();

    this->showMenu();

    return true;
}