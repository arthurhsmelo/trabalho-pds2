#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>

using std::cout;
using std::endl;

class MainScreen {
  public:
    virtual void showMenu();
    virtual ~MainScreen();
};

#endif