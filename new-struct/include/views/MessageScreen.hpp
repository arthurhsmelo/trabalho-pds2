#ifndef MESSAGESCREEN_H
#define MESSAGESCREEN_H

#include "views/MainScreen.hpp"

class MessageScreen : public MainScreen {
  public:
    virtual void showMenu() override;
};

#endif