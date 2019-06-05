#ifndef MESSAGESCREEN_H
#define MESSAGESCREEN_H

#include "views/MainScreen.hpp"
#include "models/Message.hpp"
#include "daos/daos/MessageDAO.hpp"

/**
 *  Classe view para as opções de mensagem do sistema.
 */
class MessageScreen : public MainScreen {
  
  public:
    /**
     *  Mostra o menu de mensagens
     */
    void showMenu() override;

    /**
     *  Mostra o menu da opcao visualizar conversa
     * 
     */
    void showConversationMenu();
  private:
    /**
     *  Imprime uma mensagem na tela
     * 
     *  @param objeto message a ser impresso
     */ 
    void printMessage(Message);

    /**
     *  Pergunta por um username de destinatario e verifica se ele esta cadastrado
     * 
     *  @param string username do destinatario
     */ 
    void askForUserName (string&);

    /**
     *  Preenche um objeto message com escolhas do usuario
     * 
     *  @param string username do destinatario
     */
    void messageFiller(string);

    /**
     *  Seleciona uma mensagem por id, exibe e apaga apos confirmacao
     */
    void messageEraser();

    /**
     *  Procura todas as mensagens entre o usuario logado e o destinatario
     * 
     *  @return string com o username do destinatario escolhido 
     */
    string selectConversation();  

    /**
     *  Mostra as ultimas mensagens de uma conversas com destinatarios diferentes
     * 
     */
    void showLastFiveMessages();   
    /**
     *  Mostra as ultimas mensagens de uma conversas
     * 
     */
    void printConversation(string);
};

#endif