#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <vlc/vlc.h>


int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	const char *server="localhost";
	const char *user="root";
	const char *passwd="passwd";
	const char *db="songs";

	conn = mysql_init(NULL);

	if(!mysql_real_connect(conn, server, user, passwd, db, 0, NULL, 0)){
		printf("Err : %s\n", mysql_error(conn));
		exit(1);
	}

	if(mysql_query(conn, "select * from playlist")){
		printf("Err : %s\n", mysql_error(conn));
		exit(2);
	}	
	
	res = mysql_use_result(conn);

	while((row = mysql_fetch_row(res)) != NULL)
		printf("%s \n", row[0]);


	mysql_free_result(res);
	mysql_close(conn);


	return 0;
}
