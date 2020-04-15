// Food_Warehouse_Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <WS2tcpip.h>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlite3.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <fstream> 
#include <vector>
#include <sstream>
#include <string.h>


using namespace std;

sqlite3* db;
string str1 = "";

static int callback(void* data, int argc, char** argv, char** azColName) {
	int i;

	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		str1 += argv[i];
		str1 += '*';
		str1 += " ";
	}
	str1 += "\n";

	cout << str1 << endl;

	printf("\n");
	return 0;
}
vector<string> split(const string& s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

int main(int argc, char* argv)
{
	/* SOCKET sock, clientsock;
	 WSADATA wsa;
	 struct sockaddr_in sockinfo, clientinfo;
	 int clientsize;
	 char message[] = "hello Huy";
	 if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		 printf("I am from Vietnam");
		 sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		 if (sock == INVALID_SOCKET)
			 printf("cannot connect ");
		 memset(&sockinfo, 0, sizeof(sockinfo));
		 sockinfo.sin_family = AF_INET;
		 sockinfo.sin_port = htons(12345);
		 sockinfo.sin_addr.s_addr = htonl(INADDR_ANY);
		 if (bind(sock, (SOCKADDR*)&sockinfo, sizeof(sockinfo)) == SOCKET_ERROR)
			 printf("bind ok");
		 if (listen(sock, 5) == SOCKET_ERROR)
			 printf("connected");
		 clientsize = sizeof(clientinfo);
		 printf("waiting for connection");
			 clientsock = accept(sock, (SOCKADDR*)&clientinfo, &clientsize);
		 if (clientsock == INVALID_SOCKET)
			 printf("connection failed");
		 send(clientsock, message, sizeof(message), 0);
		 closesocket(sock);
		 closesocket(clientsock);
		 WSACleanup();*/
		 //Socket test




		 //// While loop: accept and echo message back to client
		 //    send(clientSocket, message, sizeof(message), 0);
		 //    char buf[4096];


		 //    while (true)
		 //    {
		 //        ZeroMemory(buf, 4096);

		 //        // Wait for client to send data
		 //        int bytesReceived = recv(clientSocket, buf, 4096, 0);
		 //        if (bytesReceived == SOCKET_ERROR)
		 //        {
		 //            cerr << "Error in recv(). Quitting" << endl;
		 //            break;
		 //        }

		 //        if (bytesReceived == 0)
		 //        {
		 //            cout << "Client disconnected " << endl;
		 //            break;
		 //        }

		 //        cout << string(buf, 0, bytesReceived) << endl;
		 //        send(clientSocket, message, sizeof(message), 0);
		 //    }









			/* sqlite3* DB;
			 int exit = 0;
			 std::string sql = "Food warehouse management("
				 "FOOD ID INT PRIMARY KEY     NOT NULL, "
				 "FOOD NAME           TEXT    NOT NULL, "
				 "FOOD TYPE          TEXT     NOT NULL, "
				 "FOOD NUMBER            INT     NOT NULL, "
				 "UNIT        TEXT, "
				 "Type of storage         TEXT NOT NULL,"
				 "Expiry date DATE NOT NULL);";

			 exit = sqlite3_open("foodmanagement.db", &DB);
			 char* messaggeError;
			 exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
			 if (exit != SQLITE_OK) {
				 std::cerr << "Error Create Table" << std::endl;
				 sqlite3_free(messaggeError);
			 }
			 else
				 std::cout << "Table created Successfully" << std::endl;
			 sqlite3_close(DB);
			*/
			// Pointer to SQLite connection

	char* zErrMsg = 0;
	int rc;
	string sql;
	const char* data = "Callback function called";
	sqlite3_stmt* statement;
	/* Open database */
	rc = sqlite3_open("foodwarehouse.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}


	/////* Create SQL statement */
	//sql = "CREATE TABLE FOODMANAGEMENT("  \
 //       "ID INT PRIMARY KEY     NOT NULL," \
 //       "NAME           TEXT    NOT NULL,"\
 //       "BRAND          TEXT    NOT NULL,"\
 //       "TYPE           TEXT    NOT NULL," \
 //       "NUMBER         TEXT     NOT NULL," \
 //       "EXPIRYDATE     TEXT    NOT NULL);";

	///* Execute SQL statement */
	//rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	//if (rc != SQLITE_OK) {
	//    fprintf(stderr, "SQL error: %s\n", zErrMsg);
	//    sqlite3_free(zErrMsg);
	//}
	//else {
	//    fprintf(stdout, "Table created successfully\n");
	//}
	///* Create SQL statement */
	//sql = "INSERT INTO FOODMANAGEMENT (ID,NAME,BRAND,TYPE,NUMBER,EXPIRYDATE) "  \
 //       "VALUES (1, 'Chicken Eggs','KHU', 'Refrigerated', 2, '2020-05-15' ); " \
 //       "INSERT INTO FOODMANAGEMENT (ID,NAME,BRAND,TYPE,NUMBER,EXPIRYDATE) "  \
 //       "VALUES (2, 'Corn','DHA', 'Room', 3,'2020-04-15' ); "     \
 //       "INSERT INTO FOODMANAGEMENT (ID,NAME,BRAND,TYPE,NUMBER,EXPIRYDATE)" \
 //       "VALUES (3, 'Honey','VNU', 'Room', 4, '2021-03-15' );" \
 //       "INSERT INTO FOODMANAGEMENT (ID,NAME,BRAND,TYPE,NUMBER,EXPIRYDATE)" \
 //       "VALUES (4, 'Cabbage','HCMUT', 'Refrigerated',5,'2020-05-24' );";

	///* Execute SQL statement */
	//rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	//if (rc != SQLITE_OK) {
	//    fprintf(stderr, "SQL error: %s\n", zErrMsg);
	//    sqlite3_free(zErrMsg);
	//}
	//else {
	//    fprintf(stdout, "Records created successfully\n");
	//}
	// /* Create SQL statement */
	//sql = "SELECT * from FOODMANAGEMENT";

	///* Execute SQL statement */
	//rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

	//if (rc != SQLITE_OK) {
	//    fprintf(stderr, "SQL error: %s\n", zErrMsg);
	//    sqlite3_free(zErrMsg);
	//}
	//else {
	//    fprintf(stdout, "Operation done successfully\n");
	//}
	//sqlite3_close(db);

	// Initialize winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	char message[] = "I am LE QUANG HUY";
	char buffer[4096];
	int wsok = WSAStartup(ver, &wsData);
	if (wsok != 0)
	{
		cerr << "Cannot initialize winsock!" << endl;
		return -1;
	}

		// Create a socket
		SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
		if (listening == INVALID_SOCKET)
		{
			cerr << "Can't create a socket!" << endl;
			return -1;
		}

		// Bind the ip address and port to a socket
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(54000);
		hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton ....
		
		bind(listening, (sockaddr*)&hint, sizeof(hint));

		// Tell Winsock the socket is for listening
		listen(listening, SOMAXCONN);
		// Wait for a connection
		sockaddr_in client;
		int clientSize = sizeof(client);
		

		char host[NI_MAXHOST];		// Client's remote name
		char service[NI_MAXSERV];	// Service (i.e. port) the client is connect on

		ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
		ZeroMemory(service, NI_MAXSERV);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
		{
			cout << host << " connected on port " << service << endl;
		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
			cout << host << " connected on port " <<
				ntohs(client.sin_port) << endl;
		}

		// Close listening socket

		//closesocket(listening);

		/*send(clientSocket, "Hello, Huy", 13, 0);*/


		while (1)
		{
		    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

			ZeroMemory(buffer, 4096);
			int bytesReceived = recv(clientSocket, buffer, 4096, 0);

			if (bytesReceived == SOCKET_ERROR)
			{
				cerr << "Error reading from socket" << endl;

			}

			cout << string(buffer, 0, bytesReceived) << endl;

			switch (buffer[0])
			{

			case 'd':
				sql = "SELECT * from FOODMANAGEMENT";
				rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
				send(clientSocket, str1.c_str(), str1.size(), 0);
				str1.clear();
				break;
			case 'a':
				string str2(buffer);
				vector<string> a = split(str2, '+');

				sql = "INSERT INTO FOODMANAGEMENT (ID,NAME,BRAND,TYPE,NUMBER,EXPIRYDATE) "\
					"VALUES ( '" + a[1] + "','" + a[2] + "','" + a[3] + "','" + a[4] + "','" + a[5] + "','" + a[6] + "');";
				rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
				a.clear();
				str1.clear();
				str2.clear();
				break;

			}
			switch (buffer[0])
			{

			case 'u': 
				string str3(buffer);
				vector<string> u = split(str3, '+');
				sql = "UPDATE FOODMANAGEMENT set NUMBER='" + u[5] + "' where ID='" + u[1] + "' OR NAME='" + u[2] + "'    ; " \
					"UPDATE FOODMANAGEMENT set EXPIRYDATE='" + u[6] + "' where ID='" + u[1] + "' OR NAME='" + u[2] + "'   ; " \
					"UPDATE FOODMANAGEMENT set TYPE='" + u[4] + "' where ID='" + u[1] + "' OR NAME='" + u[2] + "' ; " \
					"SELECT * from FOODMANAGEMENT ";
				rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
				send(clientSocket, str1.c_str(), str1.size(), 0);
				u.clear();
				str1.clear();
				str3.clear();
				break;
			}
			switch (buffer[0])
			{
			case 'e':
				string str4(buffer);
				vector<string> e = split(str4, '+');
				sql = "DELETE FROM FOODMANAGEMENT where ID='" + e[1] + "' OR NAME='" + e[2] + "' OR BRAND='" + e[3] + "' OR TYPE='" + e[4] + "' OR NUMBER='" + e[5] + "'; " \
					"SELECT * from FOODMANAGEMENT ";
				rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
				send(clientSocket, str1.c_str(), str1.size(), 0);
				e.clear();
				str1.clear();
				str4.clear();
				break;
			}
			switch (buffer[0])
			{
			case 's':
				string str5(buffer);
				vector<string> b = split(str5, '+');
				sql = "SELECT * FROM FOODMANAGEMENT where BRAND  GLOB '*" + b[3] + "*'";
				rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
				send(clientSocket, str1.c_str(), str1.size(), 0);
				b.clear();
				str1.clear();
				str5.clear();
				break;
			}
			switch (buffer[0])
			{
			case 't':
				string str6(buffer);
				vector<string> t = split(str6, '+');
				sql = "SELECT * FROM FOODMANAGEMENT where TYPE  GLOB '*" + t[4] + "*'";
				rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
				send(clientSocket, str1.c_str(), str1.size(), 0);
				t.clear();
				str1.clear();
			
				break;
			}
			
			if (bytesReceived == 0)
			{
				cout << "Client disconnected " << endl;

			}
			Sleep(1);
			// Close the socket
			closesocket(clientSocket);
			
		}
		closesocket(listening);
		// Cleanup winsock
		WSACleanup();
	

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file