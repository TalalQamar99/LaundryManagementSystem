#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//this class handles admin login 
class AdminLogin{
	
private:
	string adminID = "admin";
	string adminPas = "adminpass";
protected:
	string adminData = "adminData.txt"; //file containng data for administrators
	string orders = "orders.txt"; //file containing a list of all the orders and their status.
	string status;
public :
	void login();
	class adminError{};
};
class AdminOrders : public AdminLogin{
protected:
	string cms;
	string room;
	string status = "ORDER PENDING";
	int regularClean; //Number of items for regular cleaning. In hostels we have different rate for normal clothes
	int specialClean; //items like towels and jackets have different rate so they are included in special cleaning.
	int numOrd;
	int penOrd;
	int deliOrd;
	double total_stu; //total  amount to be paid by student
	double total_adm; //total amount which is sum of all the payments
	double total_pending; //total amount of payment which is pending and not received yet. Since customers pay after they receive order.
public:
	AdminOrders();
	double getOrderDetails();
	void addOrder();  
	void delieverOrder();
	void updateStatus(); 
	void viewOrders(); 
	void viewFinances();
	string friend getTime(); 


};
