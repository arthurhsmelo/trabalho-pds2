#ifndef MESSAGEDAO_H
#define MESSAGEDAO_H

#include "models/Message.hpp"
#include "daos/DAO.hpp"

#include <iostream>
#include <string>

using std::string;

class MessageDAO : public DAO {
    public:
        /*
         *  Busca Nome da Tabela         
         *           
         *  @return string nome da tabela.
        */
        string getTableName();

        /*
         *  Busca nome da chave primaria da tabela         
         *           
         *  @return string nome da chave primaria da tabela.
        */
        string getPrimaryKey();

        /*
         *  Insere uma Message no BD     
         *           
         *  @param Message a ser inserido na tabela.
        */
        void createMessage(Message);

        /*
         *  Recupera uma Message no BD     
         *           
         *  @param integer correspondente ao Message a ser recuperado.
         * 
         *  @return Message recuperado do BD.
        */
        Message recoverMessageByID(int);

        /*
         *  Apaga uma Message no BD     
         * 
         *  @param integer correspondente ao Message a ser apagado.
        */
        void deteleMessage(int);

        /*
         *  Transforma uma querry recuperada do BD em uma Message    
         *           
         *  @param querry organizada em um vetor de MAP de strings.
         * 
         *  @return vetor que armazena a querry transformada em Message.
        */
        vector<Message> queryToMessage (vector<map<string, string>>);

        /*
         *  Busca no BD todas as messages trocados entre dois usuarios (conversa)    
         *           
         *  @param string com a username do usuario logado.
         *  @param string com a username do outro usuario da conversa (destinatario).
         * 
         *  @return vetor que armazena as mensagens da conversa.
        */
        vector<Message> selectConversation(string, string);

        /*   
         *  Busca as ultimas mensagens de uma conversas com destinatarios diferentes
         *        
         *  @param string com o username do usuario logado.
         * 
         *  @return vetor que armazena as mensagens selecionadas.
        */
        vector<Message> selectFiveLastMessages(string);
};

#endif