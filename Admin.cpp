#include "Admin.h"
using namespace std;

//This function handles the login process of
//admin. Password is hardcoded to "adminpass" and
//username for admin login is admin.
void AdminLogin::login(){
	int logged_in;
	string name,pass;
		cout << "Enter user name : ";
		cin >> name;
		cin.ignore();
		cout << "Enter Password : ";
		cin >> pass;
		if (name == adminID && pass == adminPas)
		{
		cout <<endl <<setw(60) << "Logging in ||";
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
		
			logged_in = 1;
		}
		else
		{
			throw 1;
		}
	}
AdminOrders::AdminOrders(){ numOrd = 0; penOrd = 0; deliOrd = 0; total_adm = 0; }

//This function is called in addOrder function to get details of order. It returns the total
//amount to be paid for a order. which is then added to the total finances of admin.
double AdminOrders::getOrderDetails()
	{
		cout << "\nEnter the Room number : ";
		cin >> room;
		cout << "\nEnter CMS ID of Student : ";
		cin >> cms;
		cout << "\nEnter number of Items for Regular Cleaning : ";
		cin >> regularClean;
		cout << "\nEnter Number of Items for Special Cleaning : ";
		cin >> specialClean;
		cout << "Order HAS BEEN ADDED " << endl;
		total_stu = regularClean * 20 + specialClean * 50;
		fstream updateOrders(orders.c_str(), ios::app);
		if (!updateOrders)
		{
			throw adminError();
		}
		updateOrders << cms << "," << room << "," << total_stu << "," << regularClean << "," << specialClean << ","<< status<<"," <<getTime();
		updateOrders.close();
		return total_stu;
	}

///This function deals with adding orders. It takes details of orders 
//and then puts them in a file.It also update adminData.txt so that 
//the record of totals orders pending and delievered is maintained.It calls
// getOrderDetails() function to get details of orders.
void AdminOrders::addOrder()
	{
		cin.ignore();
		fstream	ReadAdminData(adminData, ios::out|ios::in);//adminData.txt is being opened here in input mode to real data from file so it can be updated
		if (!ReadAdminData)
		{
			throw adminError();
		}
		ReadAdminData >> numOrd;
		ReadAdminData.ignore(numOrd,',');
		ReadAdminData >> penOrd;
		ReadAdminData.ignore(numOrd, ',');
		ReadAdminData >> deliOrd;
		ReadAdminData.ignore(numOrd,',');
		ReadAdminData >> total_adm;
		ReadAdminData.ignore(numOrd, ',');
		ReadAdminData >> total_pending;
		total_adm += getOrderDetails();
		total_pending += total_adm;
		numOrd++;
		penOrd++;
		ofstream updateAdminData(adminData, ios::out); 	//writing updated data to adminData.txt file
		if (!updateAdminData)
		{
			throw adminError();
		}
		updateAdminData << numOrd << "," << penOrd << "," << deliOrd << "," << total_adm <<"\n";
		updateAdminData.close();
	}


// This function takes a cms id and changes the status of order to *DELIEVERED *. 
//It also updates adminData.txt file.In real life this function is called when a
//customer comes  to pick up his order.
void AdminOrders::delieverOrder(){
	int counter = 4;
		string temp_t, temp_reg, temp_spec, temp_stat,new_Stat,temp_cms,temp_time;
		cout << "Enter the CMS ID for Delievering Order  : ";
		getline(cin, temp_cms,'\n');
		new_Stat = "*DELIEVERED *";
		fstream updateOrderStatus(orders, ios::in | ios::out);
		updateOrderStatus.clear();
		updateOrderStatus.seekg(0);
		while (getline(updateOrderStatus, cms, ',')&&
		getline(updateOrderStatus, room, ',')&&
		getline(updateOrderStatus, temp_t, ',')&&
		getline(updateOrderStatus, temp_reg, ',')&&
		getline(updateOrderStatus, temp_spec, ',')&&
		getline(updateOrderStatus, temp_stat, ',')&&
		getline(updateOrderStatus, temp_time, '\n'))
		{
			
			if (cms == temp_cms && (temp_stat =="ORDER PENDING" || temp_stat =="/***READY***/"))
			{

				cout << "===>THE ORDER HAS BEEN DELIEVERED TO THE CUSTOMER.<=== " << endl;
				updateOrderStatus.seekp(-40, ios::cur);
				updateOrderStatus << new_Stat;
				updateOrderStatus.close();
	
				////reading and updating the file containing admin data so that number of delievered orders is increased/////
				ifstream ReadAdminData;	//adminData.txt is being opened here in input mode to real data from file so it can be updated
				ReadAdminData.open(adminData, ios::in);
				if (!ReadAdminData)
				{
					throw adminError();
				}
				ReadAdminData >> numOrd;
				ReadAdminData.ignore(numOrd, ',');
				ReadAdminData >> penOrd;
				ReadAdminData.ignore(numOrd, ',');
				ReadAdminData >> deliOrd;
				ReadAdminData.ignore(numOrd, ',');
				ReadAdminData >> total_adm;
				deliOrd++;
				penOrd--;
				ReadAdminData.close();
				ofstream updateAdminData(adminData, ios::out); 	//writing updated data to adminData.txt file
				if (!updateAdminData)
				{
					throw adminError();
				}
				updateAdminData << numOrd << "," << penOrd << "," << deliOrd << "," << total_adm<<"\n";
				updateAdminData.close();
				counter = 1;
			}
		}
		if (counter == 4)
		{
			throw 1;
		}
}

//This function updates the order status to /***READY***/ 
//In real life this function can be called once the customer's 
//order arrives from laundry to delievery store. In this way the customer can
// track when his order has reached laundry store.
void AdminOrders::updateStatus()	
	{
	int counter = 4;
	string temp_t, temp_reg, temp_spec, temp_stat, new_Stat, temp_cms,temp_time;
	cout << "ENTER CMS ID FOR UPDATING STATUS  : ";
	getline(cin, temp_cms);
	cin.ignore();
	new_Stat = "/***READY***/";
	fstream updateOrderStatus(orders, ios::out | ios::in);
	updateOrderStatus.clear();
	while (getline(updateOrderStatus, cms, ',')&&
	getline(updateOrderStatus, room, ',')&&
	getline(updateOrderStatus, temp_t, ',')&&
	getline(updateOrderStatus, temp_reg, ',')&&
	getline(updateOrderStatus, temp_spec, ',')&&
	getline(updateOrderStatus, temp_stat, ',')&&
	getline(updateOrderStatus, temp_time, '\n'))
		
	{
		

			if (cms == temp_cms && temp_stat == "ORDER PENDING")
		{

			cout << "===>THE ORDER HAS BEEN STATUS HAS BEEN CHANGED.<=== " << endl;
			updateOrderStatus.seekp(-40, ios::cur);
			updateOrderStatus << new_Stat;
			updateOrderStatus.close();

			////reading and updating the file containing admin data so that number of pending orders is decreased/////
			ifstream ReadAdminData;	//adminData.txt is being opened here in input mode to real data from file so it can be updated
			ReadAdminData.open(adminData, ios::in);
			if (!ReadAdminData)
			{
				throw adminError();
			}
			ReadAdminData >> numOrd;
			ReadAdminData.ignore(numOrd, ',');
			ReadAdminData >> penOrd;
			ReadAdminData.ignore(numOrd, ',');
			ReadAdminData >> deliOrd;
			ReadAdminData.ignore(numOrd, ',');
			ReadAdminData >> total_adm;
			ReadAdminData.close();
			ofstream updateAdminData(adminData, ios::app); 	//writing updated data to adminData.txt file
			if (!updateAdminData)
			{
				throw adminError();
			}
			updateAdminData << numOrd << "," << penOrd << "," << deliOrd << "," << total_adm << "\n";
			updateAdminData.close();
			counter = 1;
		}
	}
	if (counter != 1)
	{
		throw 1;
	}
	}

// this function prints out a list of all the pending orders. 
//It also shows statistices including all the payments.
void AdminOrders::viewOrders()
{
	string temp_var;
	ifstream vieworders(orders, ios::in);
	if (!vieworders)
	{
		throw adminError();
	}
	cout << "CMS ID\t\tROOM #\t  TOTAL AMOUNT\tREGULAR CLEANING\tSPECIAL CLEANING\tSTATUS\t\tDATE AND TIME\n";
	while (getline(vieworders,temp_var,','))
	{
		cout << temp_var << "\t\t  ";	
	} 
}

//This function shows the total orders created. Total pending orders
//and total delivered orders. It also shows amount of all orders
void AdminOrders::viewFinances()
{
	ifstream readAdminData(adminData, ios::in);
	if (!readAdminData)
	{
		throw adminError();
	}
	readAdminData >> numOrd;
	readAdminData.ignore(numOrd, ',');
	readAdminData >> penOrd;
	readAdminData.ignore(numOrd, ',');
	readAdminData >> deliOrd;
	readAdminData.ignore(numOrd, ',');
	readAdminData >> total_adm;
	cout << "TOTAL NUMBER OF ORDERS : " << numOrd << endl;
	cout << "TOTAL NUMBER OF PENDING ORDERS : " << penOrd << endl;
	cout << "TOTAL NUMBER OF DELIEVERED ORDERS : " << deliOrd << endl;
	cout << "TOTAL AMOUNT OF ALL ORDERS : " << total_adm << endl;
}

//This function returns the current system time which is written to orders.txt 
// file and shows the time when a particular order was created.
string getTime(){
	time_t ttime = time(0);
	string dt = ctime(&ttime);
	return dt;
}
