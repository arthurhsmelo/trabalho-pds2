#include "doctest.h"
#include <iostream>
#include "models/System.hpp"
#include "models/User.hpp"
#include "models/Search.hpp"
#include "exceptions/Exception.hpp"
#include "daos/daos/UserDAO.hpp"

using namespace std;

TEST_CASE("Testing Message") {
    System *session;
    
    REQUIRE_NOTHROW(session = System::getInstance());

    cout << "Criando usuário 1" << endl;
    session->signup("tst_unit_message__", "tst_unit_message__", "123", true);
    User* user = session->getLoggedUser();

    string userName = "tst_unit_message_2__";

    cout << "Criando usuário 2" << endl;
    session->signup(userName, userName, "123", false);
    Search search;
    vector<User> usersReturned = search.searchUsers(userName);
    User user2 = usersReturned[0];

    cout << "Criando mensagem" << endl;
    Message message;
    MessageDAO messageDAO;
    message.setRecipientUser(userName);    
    message.setSenderUser(user->getUserName());
    message.setContent("mensagem de teste");
    messageDAO.createMessage(message); 

    int idMessage = message.getId();

    cout << "Apagando mensagem" << endl;
    messageDAO.deteleMessage(message.getId());

    Message messageRec = messageDAO.recoverMessageByID(idMessage);

    REQUIRE(idMessage != messageRec.getId());

    cout << "Apagando usuário 1" << endl;
    session->signout();

    cout << "Apagando usuário 2" << endl;
    UserDAO userDao;
    userDao.remove(&user2);

    delete session;
}