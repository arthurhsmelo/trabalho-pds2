#include "daos/daos/SystemDAO.hpp"

bool SystemDAO::createUserTable() {
    string createQuery = "CREATE TABLE user ( user_id int(11) NOT NULL, name varchar(100) NOT NULL, password varchar(100) NOT NULL, username varchar(20) DEFAULT NULL, system_id int(11) DEFAULT NULL, qt_posts int(11) NOT NULL DEFAULT '0', qt_likes int(11) NOT NULL DEFAULT '0', qt_following int(11) NOT NULL DEFAULT '0', qt_followers int(11) NOT NULL DEFAULT '0', PRIMARY KEY (user_id) )";
    return this->createTable(createQuery);
}
bool SystemDAO::createPostTable() {
    string createQuery = "CREATE TABLE post ( post_id int(11) NOT NULL, user_id int(11) NOT NULL, qt_likes int(11) NOT NULL DEFAULT '0', qt_replies int(11) NOT NULL DEFAULT '0', qt_reposts int(11) NOT NULL DEFAULT '0', is_reply varchar(1) NOT NULL DEFAULT 'N', is_repost varchar(1) NOT NULL DEFAULT 'N', content varchar(280) NOT NULL, PRIMARY KEY (post_id) )";
    return this->createTable(createQuery);
}
bool SystemDAO::createMessageTable() {
    string createQuery = "CREATE TABLE message ( message_id int(11) NOT NULL, content varchar(45) DEFAULT NULL, sender_id int(11) NOT NULL, recipient_id int(11) NOT NULL, PRIMARY KEY (message_id) )";
    return this->createTable(createQuery);
}

string SystemDAO::getPrimaryKey() {
    return "";
};
string SystemDAO::getTableName() {
    return "";
};