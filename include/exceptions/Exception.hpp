#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using std::exception;

namespace Exception {
    class BadDataBaseInitialization : public exception {};
    class UserNotFound : public exception {};
    class InvalidPassword : public exception {};
    class UserAlreadyExists : public exception {};
}

#endif