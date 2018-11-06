#ifndef USERSCREEN_H
#define USERSCREEN_H

#include "views/MainScreen.hpp"

class UserScreen : public MainScreen {
  public:
    virtual void showMenu() override;
};

#endif