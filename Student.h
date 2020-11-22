#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class student{
protected:
	string userDb = "usersDB.txt";
	string u_id;
	string full_name;
	string room_no;
	string department;
	string cms_id;
	string password;
	string time;
public:

	class StudentError
	{
	};
	void login();
	void add_user();
	void checkStatus();
};
