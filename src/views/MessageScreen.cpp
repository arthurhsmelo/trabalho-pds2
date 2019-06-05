#include "views/MessageScreen.hpp"
#include "models/Message.hpp"
#include "models/System.hpp"
#include "models/Search.hpp"
#include "models/User.hpp"

void MessageScreen::showMenu() {
    int choice = 0;
    string userName;
    
    do {
        this->clrscr();
        this->showLastFiveMessages();
        cout << endl;
        cout << "Menu de Mensagens" << endl;
        cout << "Escolha uma opcao" << endl;
        cout << "1 - Visualizar Conversa" << endl;
        cout << "2 - Criar Nova Mensagem" << endl;
        cout << "3 - Recarregar Conversa" << endl;
        cout << "4 - Voltar" << endl;
        choice = this->getInput();
        cout << endl;
        cout << "Escolha: " << choice << endl;
        
        switch(choice) {
            case 1:
                this->showConversationMenu();
                break;
            case 2:
                this->messageFiller("");   
                break;
            case 3:                     
                break;
            case 4:
                cout << "Voltando ao Menu anterior" << endl;
                break;
            default:
                cout << "Comando invalido!" << endl;
                break;
        }

    } while(choice!=4);
}

void MessageScreen::showConversationMenu(){
    int choice = 0;
    string recipientUser = "";
    this->clrscr();
    recipientUser = this->selectConversation();
    do {
        cout << "Escolha uma opção" << endl;
        cout << "1 - Voltar" << endl;
        cout << "2 - Excluir Mensagem" << endl;
        cout << "3 - Nova Mensagem Nessa Conversa" << endl;
        choice = this->getInput();
        cout << endl;
        cout << "Escolha: " << choice << endl;

        switch(choice) {
            case 1:
                cout << "Voltando ao Menu anterior..." << endl;
                break;
            case 2:
                this->messageEraser();
                break;
            case 3:                  
                this->messageFiller(recipientUser); 
                this->clrscr();
                this->printConversation(recipientUser);
                break;
            default:
                cout << "Comando invalido!" << endl;
                break;
        }
    } while(choice!=1);
}

void MessageScreen::printMessage (Message current){
    //mudar a organização de print com o estilo padrão d etodos
    cout << "Nome do Remetente: " << current.getSenderUser(); 
    cout << " -> Nome do Destinatário: " << current.getRecipientUser() << endl; 
    cout << "'" << current.getContent() << "'" << endl;
    cout << "ID da Mensagem: " << current.getId() << endl;
    cout << endl;
}

void MessageScreen::askForUserName (string& recipientUser) {
    User* user;
    bool repeat = true;
    UserDAO userDAO;

    do{
        getline(cin, recipientUser);

        try {
            user = userDAO.select(recipientUser);
            if (user == nullptr) {
                throw Exception::UserNotFound();
            } else {
                repeat = false;
            }
        } catch(Exception::UserNotFound& e) {
            cout << "Usuario nao encontrado!" << endl;
            cout << "Tente novamente" << endl;
        }
        
    } while (repeat);
}

void MessageScreen::messageFiller(string recipientUser) {
    System *session = System::getInstance();
    Message message;
    MessageDAO messageDAO;
    string content;

    if (recipientUser == "") {
        cout << "Entre com o User do destinatario:" << endl;
        this->askForUserName(recipientUser);
    }

    message.setRecipientUser(recipientUser);
    
    message.setSenderUser(session->getLoggedUser()->getUserName());

    cout << "Entre com a mensagem:" << endl;
    getline(cin, content);
    message.setContent(content);

    messageDAO.createMessage(message); 
}


void MessageScreen::messageEraser(){
    int option = 0;
    MessageDAO messageDao;
    Message message;
    bool repeat = true;

    do {
        cout << "Qual o ID da mensagem que quer apagar?" << endl;
        option = this->getInput();

        try {
            message = messageDao.recoverMessageByID(option);
            if(message.getId() == option){
                repeat=false;
            } else {
                throw Exception::MessageNotFound();
            }
        } catch(Exception::MessageNotFound& e) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Mensagem nao encontrada!" << endl;
        }
    } while(repeat);

    this->printMessage(message);

    cout << "Tem certeza que quer apagar essa mensagem?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    option = this->getInput();
    if (option == 1){
        messageDao.deteleMessage(message.getId());  
        cout << "Mensagem apagada!" << endl;
    } 
}

void MessageScreen::printConversation(string recipientUser) {
    vector<Message> conversation;
    Search search;
    System *session = System::getInstance(); 

    conversation = search.selectConversation(session->getLoggedUser()->getUserName(), recipientUser); 
    if (conversation.size() > 0){
        cout << " ------------------------------------ " << endl;
        cout << " -- Conversa com " << recipientUser <<  ": -- " << endl;
        cout << " ------------------------------------ " << endl;
        for (auto message: conversation){
            this->printMessage(message);
        }
    } else {
        cout << "Nao existem mensagens nessa conversa!" << endl;
    }
}

string MessageScreen::selectConversation(){
    string recipientUser="";
    
    cout << "Quer ver a sua conversa com qual Usuario?" << endl;

    this->askForUserName(recipientUser);
    this->printConversation(recipientUser);

    return recipientUser;
}  

void MessageScreen::showLastFiveMessages(){
    Search search;
    vector<Message> lastMessages = search.selectFiveLastMessages();
    
    if (lastMessages.size() > 0){
        cout << " ------------------------------------ " << endl;
        cout << " ------- Mensagens recentes: -------- " << endl;
        cout << " ------------------------------------ " << endl;
        for (auto message: lastMessages){
            this->printMessage(message);
        }
    } else {
        cout << endl << "Voce nao possui mensagens recentes!" << endl;
    }
}   



