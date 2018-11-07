#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include "exceptions/Exception.hpp"
#include "models/System.hpp"

using std::cout;
using std::endl;

class MainScreen {
  public:
    virtual void showMenu();
    virtual ~MainScreen();
  protected:
    void clrscr();
    int getInput();
};

#endif