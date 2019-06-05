#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "exceptions/Exception.hpp"
#include "models/System.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::out_of_range;

/**
 *  Classe principal das views do sistema.
 *  Responsável por centralizar os menus e implementar o menu principal.
 */
class MainScreen {
  public:
    /**
     *  Mostra o menu principal.
     */
    virtual void showMenu();
    /**
     *  Destrutor.
     */
    virtual ~MainScreen();
  protected:
    /**
     *  Limpa a tela, OS Independent
     */
    void clrscr();
    /**
     *  Requisita o usuário um número válido.
     *  
     *  @return int valor válido digitado pelo usuário
     */
    int getInput();
  private:
    /**
     *  Mostra o menu de configurações.
     */
    void showConfigOptions();
};

#endif