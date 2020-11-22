#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*This function handles all the login process. Student enters CMS ID
with which he registered with the system and his password which are stored
in userDB file. The same file is searched  by this function to check
login credentials. */
void student::login()			
	{

	int counter = 5;
		fstream searchUser(userDb.c_str(), ios::in|ios::app);	//opening file to search a users credentials
		if (!searchUser)
		{
			throw StudentError();							//throw exception if file not opened
		}
		string cmsr;
		string passr;
		cin.ignore();
		cout << "Enter your CMS ID : ";
		getline(cin, cmsr);
		cout << "Enter your password : ";
		getline(cin, passr);
		while (getline(searchUser, full_name, ',')&&
		getline(searchUser, room_no, ',')&&
		getline(searchUser, department, ',')&&
		getline(searchUser, cms_id, ',')&&
		getline(searchUser, password, '\n')) // using getline inside while loop to read the userDB file and finding if student exists.
		{
			
			if (cms_id == cmsr && passr == password)
			{
				cout << endl<<setw(60) << "Logging in ||";
				Sleep(500);
				cout << "|";
				Sleep(500);
				cout << "|";
				Sleep(500);
				cout << "|";
				Sleep(500);
				cout << "|";
				Sleep(500);
				cout << "|";
				Sleep(500);
				cout << "|";
				system("cls");
				cout << endl << endl << setw(45) << "LOGIN SUCCESSFUL" << endl;
				cout << setw(45) << "----------------" << endl;
				Sleep(500);
				counter = 1;
			}
		}
		if (counter != 1)
		{
			throw 1;
		}
		searchUser.close();								//close the file
		_getch();
	}


/*This function is used to add a new student to the management system so that in future 
the student can login and track the status of hiis clothes. */
void student::add_user()
	{
		ofstream registeruser(userDb, ios::app);
		if (!registeruser)
		{
			throw StudentError();
		}
		cin.ignore();
		cout << "Enter your full Name : ";
		getline(cin, full_name);
		cout << "Enter your Room Number : ";
		getline(cin, room_no);
		cout << "Enter your Department : ";
		getline(cin, department);
		cout << "Enter your CMS ID : ";
		getline(cin, cms_id);
		cout << "Enter your password : ";
		getline(cin, password);
		registeruser << full_name << "," << room_no << "," << department << "," << cms_id << "," << password<<endl;
		registeruser.close();
		cout << "Your are registered to the system. You can now use your CMS and PASSWORD to track your clothes. " << endl;
	}
/* This function is used to track the status of the clothes. Every order is created using 
student's CMS ID and the same CMS ID can be used to track the status of the student.*/
void student::checkStatus() 
{
	string temp_cms, temp_t, temp_reg, temp_spec, temp_stat,temp_time;
	int counter = 4;
	cout << "Enter the CMS ID to search order : ";
	getline(cin, temp_cms);
	ifstream searchOrder("orders.txt", ios::in);
	if (!searchOrder)
	{
		throw StudentError();
	}
	while (getline(searchOrder, cms_id, ',') && getline(searchOrder, room_no, ',') && getline(searchOrder, temp_t, ',')
		&& getline(searchOrder, temp_reg, ',') && getline(searchOrder, temp_spec, ',') && getline(searchOrder, temp_stat, ',')&& 
		getline(searchOrder,temp_time,'\n'))
	{

		if (cms_id == temp_cms)
		{
			cout << endl;
			cout  << "\t\t\tORDER(S) HAS BEEN FOUND." << endl;
			cout << "\t\tCMS ID : " << cms_id << endl;
			cout << "\t\tROOM NUMBER : " << room_no << endl;
			cout << "\t\tTOTAL AMOUNT : " << temp_t << endl;
			cout  << "\t\tREGULAR CLEANING : " << temp_reg << endl;
			cout << "\t\tSPECIAL CLEANING : " << temp_spec << endl;
			cout << "\t\tORDER STATUS : " << temp_stat << endl;
			cout << "\t\tTHE TIME OF ORDER IS : " << temp_time << endl;
			cout << endl;
			cout << endl;
			counter = 1;
			
		}
	}
	if (counter != 1)
	{
		throw 1;
	}
}
