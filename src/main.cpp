#include <iostream>
#include <string>

#include "Message.hpp"
#include "Post.hpp"
#include "Search.hpp"
#include "System.hpp"
#include "User.hpp"
#include "sqlite3/sqlite3.h"
#include "DAO/dao.hpp"


using namespace std;
  
int main() {
	const int STATEMENTS = 8;
	const char *pSQL[STATEMENTS];

  DAO *dao = DAO::getInstance();

	pSQL[0] = "create table myTable (FirstName varchar(30), LastName varchar(30), Age smallint, Hometown varchar(30), Job varchar(30))";

	pSQL[1] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Peter', 'Griffin', 41, 'Quahog', 'Brewery')";
	
	pSQL[2] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Lois', 'Griffin', 40, 'Newport', 'Piano Teacher')";
	
	pSQL[3] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Joseph', 'Swanson', 39, 'Quahog', 'Police Officer')";
	
	pSQL[4] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Glenn', 'Quagmire', 41, 'Quahog', 'Pilot')";

	pSQL[5] = "select * from myTable";	
  
  pSQL[6] = "delete from myTable"; 

	pSQL[7] = "drop table myTable";

	for(int i = 0; i < STATEMENTS; i++) {
    if(i != 5) {
      dao->insert(pSQL[i]);    
    } else {
      dao->select(pSQL[i]);
    } 
	}

	sqlite3_close(dao->getConnection());

	return 0;
}
