#ifndef DAO_H
#define DAO_H

#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include <algorithm>
#include "lib/sqlite/sqlite3.h"
#include "daos/Connection.hpp"

using std::string;
using std::map;
using std::vector;

/**
 *  Data Access Object.
 *  Responsável por centralizar todas as conexões com o banco.
 */
class DAO {
    /**
     *  Tipo que representa uma linha.
     *  Ajuda na leitura do retorno das intruções processadas pelo sqlite3.
     */
    struct row {
        int numberOfCols;
        vector<string> rowValues;
        vector<string> colsNames;
    };
    char *zErrMsg = 0;       /**< Utilizado para armazenar erros do sqlite3 */   
    int dbStatus;            /**< Utilizado para o status da última execução do sqlite3 */   
    sqlite3 *sqliteConn;     /**< Utilizado para armazenar o sqlite3 */   
    row returnedRow;         /**< Utilizado para armazenar a última linha retornada pelo sqlite3 */   
    vector<map<string, string>> fetchedRows;    /**< Utilizado para armazenar o último select feito pelo sqlite3 */   

    /**
     *  Recebe o retorno do sqlite3.
     *  Callback utilizado pelo sqlite3, para retornar os resultados das execuções, utilizado para buildar as rows
     *  e armazená-las na varável #fetchedRows.
     * 
     *  @param void*    dados que o sqlite passa da função de origem para o callback. Nesse caso, foi passada a própia instância da classe DAO.
     *  @param int      número de colunas retornadas pelo sqlite3
     *  @param char**   array de strings com os valores para cada uma das colunas
     *  @param char**   array de strings com os nomes de cada uma das colunas 
     * 
     *  @return int 0
     *  @see http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
     */
    static int callback(void*, int, char**, char **);
    /**
     *  Builda uma row.
     *  Função utilizada pelo #callback(void*, int, char**, char **), para montar um map<string, string> com a última row retornada #returnedRow
     * 
     *  @return map<string, string> um Mapa representando a última row retornada pelo sqlite3
     */
    map<string, string> fetchRow();
    /**
     *  Seta o número de colunas retornados pelo sqlite3 na #returnedRow.
     *  
     *  @param int número de colunas retornados pelo #callback
     */
    void setNumberOfCols(int);
    /**
     *  Seta o número de colunas retornados pelo sqlite3 na #returnedRow.
     *  
     *  @param char** rowValues retornados pelo #callback
     */
    void setRowValues(char**);
     /**
     *  Seta o número de colunas retornados pelo sqlite3 na #returnedRow.
     *  Utiliza o construtor de iterator do vector para transformar char** em vector<string>
     *  
     *  @param char** colsNames retornados pelo #callback
     */
    void setColsNames(char**);
    /**
     *  Retorna o número de colunas retornados pelo sqlite3 da #returnedRow.
     *  
     *  @return int número de colunas
     */
    int getNumberOfCols();

    public:
        /**
         *  Construtor.
         *  Inicializa o banco de dados no arquivo database.db, instanciando, 
         *  pela primeira vez um objeto do singleton Connection.
         */
        DAO();
        /**
         *  Executa uma query sql.
         *  Centraliza todas as execuções de queries.
         * 
         *  @param string Query SQL a ser executada.
         * 
         *  @return int inteiro representado o resultado da query(se houve erro resultado != 0)
         *  @see https://www.sqlite.org/c3ref/c_abort.html
         */
        int exec(string);

    protected:
        /**
         *  Executa um select.
         *  Retorna um vetor de mapas. Sendo que cada item do vetor, representa uma linha 
         *  retornada pela query. Cada mapa(um por item do vetor) tem como chaves os nomes das colunas da tabela,
         *  valores, o retorno do select para esta coluna.
         * 
         *  @param string SELECT a ser executado.
         * 
         *  @return vector<map<string, string>> o retorno da query
         */
        vector<map<string, string>> select(string);
        /**
         *  Executa um insert.
         * 
         *  @param string INSERT a ser executado.
         * 
         *  @return bool true se tudo deu certo
         */
        bool insert(string);
        /**
         *  Executa um delete.
         * 
         *  @param string DELETE a ser executado.
         * 
         *  @return bool true se tudo deu certo
         */
        bool remove(string);
        /**
         *  Executa um update.
         * 
         *  @param string UPDATE a ser executado.
         * 
         *  @return bool true se tudo deu certo
         */
        bool update(string);
        /**
         *  Executa uma create.
         * 
         *  @param string CREATE a ser executado.
         * 
         *  @return bool true se tudo deu certo
         */
        bool createTable(string);
        /**
         *  Busca o maior número da primary key da tabela que está utilizando este método.
         *  Utiliza os métodos virtuais #getTableName() e #getPrimaryKey para buscar o 
         *  maior id na coluna PK da tabela, e retornar o próximo id, para evitar erros de PK duplicada.
         * 
         *  @return string o próximo id a ser salvo na coluna PK da tabela.
         */
        string getNextId(); 
        /**
         *  Utilizado pelo método #getNextId() para saber em qual tabela buscar
         * 
         *  @return string o nome da tabela
         */
        virtual string getTableName();
        /**
         *  Utilizado pelo método #getNextId() para saber qual coluna buscar
         * 
         *  @return string o nome da coluna PK
         */
        virtual string getPrimaryKey();
};

#endif