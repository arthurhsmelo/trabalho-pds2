#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using std::exception;

/**
 *  Namespace para centralizar as Exceptions
 */
namespace Exception {
    /**
     *  Lançada quando há algum erro na inicialização do bando de dados SQLITE3.
     *  Lançada por System::initialize()
     */
    class BadDataBaseInitialization : public exception {};
    /**
     *  Lançada quando o usuário tenta logar com username que não está cadastrado.
     *  Lançada por System::login()
     */
    class UserNotFound : public exception {};
    /**
     *  Lançada quando o usuário erra a senha.
     *  Lançada por System::login()
     *  Lançada por MessageScreen::askForUserName()
     */
    class InvalidPassword : public exception {};
    /**
     *  Lançada quando o usuário tenta cadastrar um username que já está cadastrado.
     *  Lançada por System::signup()
     */
    class UserAlreadyExists : public exception {};
    /**
     *  Lançada quando o usuário digitar uma opção inválida.
     *  Lançada por MainScreen::getInput()
     */
    class InvalidInput : public exception {};
    /**
     * Lanlada quando o usuário digitar uma opção inválida.
     * Lançada por MessageScreeen::messageEraser()
     */
    class MessageNotFound : public exception {};
}

#endif