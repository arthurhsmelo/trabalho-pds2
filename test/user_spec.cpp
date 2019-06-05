#include "doctest.h"
#include <iostream>
#include "models/System.hpp"
#include "models/User.hpp"
#include "models/Search.hpp"
#include "exceptions/Exception.hpp"
#include "daos/daos/UserDAO.hpp"

using namespace std;

TEST_CASE("Testing User Follow") {
    System *session;
    
    REQUIRE_NOTHROW(session = System::getInstance());

    cout << "Criando usuário 1" << endl;
    session->signup("tst_unit_user", "tst_unit_user", "123", true);
    User* user = session->getLoggedUser();

    string userName = "tst_unit_user_2";

    cout << "Criando usuário 2" << endl;
    session->signup(userName, userName, "123", false);
    Search search;
    vector<User> usersReturned = search.searchUsers(userName);
    User user2 = usersReturned[0];

    cout << "Seguindo usuário 2" << endl;
    user->setFollowings(user2); 
    
    REQUIRE(user->getQtFollowing() == "1");
    REQUIRE(user2.getQtFollowers() == "1");

    cout << "Deixando de seguir usuário 2" << endl;
    user->unfollow(user2); 
    REQUIRE(user->getQtFollowing() == "0");
    REQUIRE(user2.getQtFollowers() == "0");

    cout << "Apagando usuário 1" << endl;
    session->signout();

    cout << "Apagando usuário 2" << endl;
    UserDAO userDao;
    userDao.remove(&user2);

    delete session;
}