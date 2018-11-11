#ifndef SYSTEMSCREEN_H
#define SYSTEMSCREEN_H

#include "views/MainScreen.hpp"

class SystemScreen : public MainScreen {
  public:
    void showMenu();
  
  private:
    void requestLogin();
    void requestLogout();
    void requestSignup(bool);
    void requestSignout();

};

#endif