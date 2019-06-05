#ifndef CONN_H
#define CONN_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include "lib/sqlite/sqlite3.h"

/**
 *  Classe responsável pela conexão com o banco. 
 *  O Banco de dados utilizado foi o sqlite3. Esta classe implementa
 *  uma técnica conhecida como Singleton para conectar somente uma vez com o banco,
 *  e fornecer essa conexão para o resto do sistema, evitando múltiplas instâncias da mesma. 
 *  @see https://sourcemaking.com/design_patterns/singleton/cpp/1
 */
class Connection {
	static Connection* _instance;       /**< A instância da classe */   
    sqlite3 *sqliteConn;                /**< A conexão com o sqlite */
	
    /**
     *  Construtor privado.
     *  Necessário para a implementação do Singleton.
     */
    Connection();
 
public:
	/**
     *  Cria, se ainda não houver uma instância desta classe.
     *  
     *  @return Connection* Ponteiro para a instância única da classe.
     */
    static Connection* getInstance();

    /**
     *  Retorna a conexão
     *  
     *  @return sqlite3* Ponteiro para a conexão.
     */
    sqlite3* getConnection();
};

#endif