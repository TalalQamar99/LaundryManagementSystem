/*Project Title : Student Hostel Laundry Store Management System
Developed by : 1) Muhammad Talal Qamar Sahi
			   2) Muhammad Ayan
School of Electrical Engineering and Computer Science NUST.
*/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string>
#include "Admin.h"
#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int choose;
int main()
{
	AdminOrders a1;
	student s1;
	//main menu and its code starts here
start:
		system("cls");
		cout << endl << "Enter:" << endl;
		cout << setw(22) << "1. STUDENT LOGIN" << endl;
		cout << setw(28) << "2. ADMINISTRATOR LOGIN" << endl;
		cout << setw(29) << "3. STUDENT REGISTRATION" << endl;
		cout << setw(13) << "4. EXIT" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			try{
				s1.login();
				choose = 1;
				_getch();
			}
			catch (student::StudentError)
			{
				cout << "File could not be opened" << endl;
				_getch();
				goto start;
			}
			catch (int)
			{
				cout << endl << setw(55) << "CREDENTIALS ARE INCORRECT." << endl;
				cout << setw(42) << "TRY AGAIN" << endl << endl;
				_getch();
				system("cls");
				goto start;
			}
		}
		else if (choice == 2)
		{
			try{
				a1.login();
				choose = 2;
				_getch();
			}
			catch (int)
			{
				cout << endl << setw(55) << "CREDENTIALS ARE INCORRECT." << endl;
				cout << setw(42) << "TRY AGAIN" << endl << endl;
				_getch();
				system("cls");
				goto start;
			}
		}
		else if (choice == 3)
		{
			try{
				s1.add_user();
				choose = 1;
				_getch();
				}
			catch (student::StudentError)
			{
				cerr << "File could not be opened" << endl;
				_getch();
				goto start;
			}
		}
		else if (choice == 4)
		{
			cout << setw(44) << "=====>THANK YOU<=====" << endl;
			cout << setw(38) << "---------" << endl;
			exit(1);
		} //main menu and its code ends here


//admin menu and its code starts here	
if (choose == 2)
{
admin_main:
	system("cls");
	cout << setw(48) << "---------------------------" << endl;
	cout << endl << setw(58) << "=====>|WELCOME TO ADMINISTRATOR MENU|<=====" << endl;
	cout << setw(52) << "-------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl;
	cout << "------------------" << endl;
	cout << setw(31) << "1. ADD A ORDER" << endl;
	cout << setw(38) << "2. DISPLAY ALL ORDERS" << endl;
	cout << setw(34) << "3. DELIEVER ORDER" << endl;
	cout << setw(39) << "4. UPDATE ORDER STATUS" << endl;
	cout << setw(51) << "5. VIEW FINANCES AND OTHER DETAILS" << endl;
	cout << setw(26) << "6. LOGOUT" << endl;
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1) //admin options
	{
		try {
			system("cls");
			cout << setw(48) << "-----------------------" << endl;
			cout << endl << setw(48) << "=====>|ADD ORDER MENU|<=====" << endl;
			cout << setw(42) << "---------------" << endl << endl;
			a1.addOrder();
			_getch();
			goto admin_main;
			}
		catch (AdminOrders::adminError)
		{
			cerr << "File Could Not Be Opened." << endl;
			_getch();
			goto admin_main;
		}
	}
	else if (choice == 2)
	{
		try{
			system("cls");
			cout << endl << setw(48) << "=====>|DISPLAYING LIST OF ORDERS|<=====" << endl;
			a1.viewOrders();
			_getch();
			goto admin_main;
		}
		catch (AdminOrders::adminError)
		{
			cerr << "File Could Not Be Opened." << endl;
			_getch();
			goto admin_main;
		}

	}
	else if (choice == 3)
	{
		try{
			system("cls");
			cout << setw(48) << "-----------------------" << endl;
			cout << endl << setw(48) << "=====>|DELIEVER ORDER MENU|<=====" << endl;
			cout << setw(42) << "---------------" << endl << endl;
			a1.delieverOrder();
			_getch();
			goto admin_main;
			}
		catch (AdminOrders::adminError)
			{
			cerr << "File Could Not Be Opened." << endl;
			_getch();
			goto admin_main;
			}
		catch (int)
		{
			cerr <<endl<< "ORDER NOT FOUND IN THE LIST OR IT MAY HAVE BEEN DELIEVERED.VIEW LIST OF ORDERS FOR DETAILS \n";
			_getch();
			goto admin_main;
		}
	}
	else if (choice == 4)
	{
		try
		{
			system("cls");
			cout << setw(48) << "-----------------------" << endl;
			cout << endl << setw(48) << "=====>|UPDATE ORDER STATUS|<=====" << endl;
			cout << setw(42) << "---------------" << endl << endl;
			a1.updateStatus();
			_getch();
			goto admin_main;
				
		}
		catch (AdminOrders::adminError)
		{
			cerr << "File Could Not Be Opened." << endl;
			_getch();
			goto admin_main;
		}
		catch (int)
		{
			cerr << endl <<setw(60)<< "ORDER HAS ALREADY BEEN DELIEVERED TO CUSTOMER.OR IT DOES NOT EXIST.VIEW LIST OF ORDERS FOR DETAILS \n";
			_getch();
			goto admin_main;
		}
	}
	else if (choice == 5)
	{
		try{
			system("cls");
			cout << setw(48) << "-----------------------" << endl;
			cout << endl << setw(48) << "=====>FINANCES AND DETAILS |<=====" << endl;
			cout << setw(42) << "---------------" << endl << endl;
			a1.viewFinances();
			_getch();
			goto admin_main;
		}
		catch (AdminOrders::adminError)
		{
			cerr << endl << "UNABLE TO OPEN FILE. \n";
			_getch();
			goto admin_main;
		}
	}
	else if (choice == 6)
	{
		system("cls");
		cout << setw(44) << "=====>THANK YOU<=====" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << setw(38) << "LOGGING OUT ||";
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
		goto start;
	}
	
}//admin options end here


//student menu and its code
else if (choose == 1)
{
student_main:
	system("cls");
	cout << setw(48) << "---------------------------" << endl;
	cout << endl << setw(58) << "=====>|WELCOME TO STUDENT MENU|<=====" << endl;
	cout << setw(52) << "-------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl;
	cout << "------------------" << endl;
	cout << setw(31) << "1. VIEW ORDER STATUS" << endl;
	cout << setw(31) << "2. LOGOUT" << endl;
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		try{
			system("cls");
			cout << endl << setw(48) << "=====>|DISPLAYING ORDER STATUS|<=====" << endl;
			s1.checkStatus();
			_getch();
			goto student_main;
		}
		catch (student::StudentError)
		{
			cerr << endl << "UNABLE TO OPEN FILE. \n";
			_getch();
			goto student_main;
		}
		catch (int)
		{
			cerr << endl << "ORDER DOES NOT EXIST. \n";
			_getch();
			goto student_main;
		}
	}
	else if (choice == 2)
	{
		system("cls");
		cout << setw(44) << "=====>THANK YOU<=====" << endl;
		cout << setw(38) << "LOGGING OUT ||";
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
		goto start;
	}
	else{
		goto student_main;
	}
	
} //student menu and code ends here.
 
return 0;
}
