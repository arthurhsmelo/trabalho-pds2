#include "models/System.hpp"

System::System() {
  this->initialize();
}

System::~System() {
  Connection * conn = Connection::getInstance();
  delete this->getLoggedUser();
  delete conn;
}

System* System::getInstance() {
  if (_instance == NULL)
    _instance = new System();
  return _instance;
}

User* System::getLoggedUser() {
  return this->loggedUser;
};

void System::setLoggedUser(User* user) {
  this->loggedUser = user;
};

bool System::initializeDB() {
  SystemDAO systemDao;

  bool sCreation1 = systemDao.createUserTable();
  bool sCreation2 = systemDao.createPostTable();
  bool sCreation3 = systemDao.createMessageTable();

  if (sCreation1 && sCreation2 && sCreation3)
    return true;
  else
    return false;
}

void System::initialize() {
  cout << "Inicializando o Sistema..." << endl;
  this->setLoggedUser(nullptr);

  cout << "Inicializando o Banco de Dados..." << endl;
  bool success = this->initializeDB();

  if (success) {
    cout << "Banco de Dados inicializado" << endl << endl;
  } else {
    throw Exception::BadDataBaseInitialization();
  }
}

void System::login(string username, string password) {
  UserDAO userDao;
  User *user = userDao.select(username);
  if (user == nullptr) {
    throw Exception::UserNotFound();
  } else {
    user = userDao.select(username, password);
    if (user == nullptr) {
      throw Exception::InvalidPassword();
    } else {
      this->setLoggedUser(user);
    }
  }
}

void System::signup(string name, string username, string password, bool doLogin) {
  UserDAO userDao;
  User *user = userDao.select(username);
  if (user != nullptr) {
    throw Exception::UserAlreadyExists();
  } else {
    User *user = new User(name, username, password);
    userDao.insert(user);
    if (doLogin)
      this->setLoggedUser(user);
  }
}

void System::logout() {
  this->setLoggedUser(nullptr);
}

void System::signout() {
  UserDAO userDao;
  userDao.remove(this->getLoggedUser());
  this->setLoggedUser(nullptr);
}

System * System::_instance = NULL;