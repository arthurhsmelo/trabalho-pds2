#ifndef SYSTEMSCREEN_H
#define SYSTEMSCREEN_H

#include "views/MainScreen.hpp"

class SystemScreen : public MainScreen {
  public:
    virtual void showMenu() override;
};

#endif