#include "doctest.h"
#include <iostream>
#include "models/System.hpp"
#include "exceptions/Exception.hpp"

using namespace std;

TEST_CASE("Testing User Login/Signup and Database initialization") {
    System *session;
    //Não pode haver problema ao incializar a base
    REQUIRE_NOTHROW(session = System::getInstance());

    cout << "Criando usuário" << endl;
    session->signup("unit_tests", "unit_tests", "123", true);

    cout << "Testando usuário" << endl;
    REQUIRE(session->getLoggedUser()->getUserName() == "unit_tests");

    cout << "Deslogando" << endl;
	session->logout();
    REQUIRE(session->getLoggedUser() == nullptr);

    cout << "Tentando logar com senha errada" << endl;
    REQUIRE_THROWS_AS(session->login("unit_tests", "1234"), Exception::InvalidPassword);

    cout << "Logando" << endl;
    REQUIRE_NOTHROW(session->login("unit_tests", "123"));

    cout << "Apagando usuário" << endl;
    session->signout();

    delete session;
}

