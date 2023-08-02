#pragma once

#include"Header.h"
#include"inventory1.h"
#include"manager.h"
#include"costumer.h"
#include<iostream>
#include"fstream"
using namespace std;

class admin :public user
{
private:

	char name[30]; char cnic[30];
	manager man_data;
	char stores[10];

	//	string stores[3] = { "Rawalpindi","Islamabad","Karachi" };
public:
	catalog o;
	admin(string username1, string pass1)
	{
		strcpy_s(username, username1.c_str());
		strcpy_s(password, pass1.c_str());



		//strcpy_s(name, n1.c_str());
		//strcpy_s(cnic, cnic1.c_str());
	}
	admin(string sto1)
	{
		strcpy_s(stores, sto1.c_str());
	}
	void home()
	{
		bool go = true;
		int ans;

		while (go)
		{
			system("cls");

			heading("HOME");
			cout << " You want to:\n"
				<< "\t1) Add Manager\n"
				<< "\t2) Search Manager by cnic\n"
				<< "\t3) View Managers\n"
				<< "\t4) Delete Products\n"
				<< "\t5) Edit Products\n"
				<< "\t6) View employee records\n"
				<< "\t6)  Delete manager       \n"
				<< "\t7) Show Catalog\n"
				<< "\t8) Add prod\n"
				<<"\t\9) edit manager\n"
				<<" \t10)show customer\n"
				<<"\t11) Remove Customer\n "
				<<"\t12) Show feedbacks \n"
				<<"\t13) Remove Feedbacks \n"
				<<"\t14) Back\n";

			cout << "\n Your choice > ";
			cin >> ans;

			switch (ans)

			{
			case 1:

				registermanager();
				_getch(); break;

			case 2:
				manager_display_data(); break;
			case 3:
				system("cls");
				showallmanagers(); break;
			case 4:
				o.delete_prod(); break;
				//manager_display_data(); break;
			case 5:
				o.edit_prod(); break;
			case 6:
				delete_manager(); break;
			case 7:


				o.show_prod(); break;
			case 8:

				o.add_prod(); break;
			case 9:
				edit_manger(); break;
			case 10:
				showallcustomerss(); break;
			case 11:
				remove_spam(); break;
				//update_manager_location(); break;
			case 12:
				show_feedback(); break;
			case 13:
				remove_feedback(); break;
			case 14:
				go = false;
				cout << "You have been  logged out: " << endl;
				break;

				
			}



		}
	}

	void display()
	{
		cout << "UserName: " << username << endl;

		cout << "Password: " << password << endl;


	}
	void Login()
	{
		string U, P;
		cout << "Enter Username:  " << endl;
		cin >> U;
		cout << endl;
		cout << "Enter Password: " << endl;
		cin >> P;
		cout << endl;
		if (U == username && P == password)
			cout << "Welcome to the admin of " << U << "!" << endl;
		else {

			cout << "Wrong credentials, Enter again!" << endl;

			Login();

		}
		home();
	}
	void write(string file_name, manager obj)
	{
		ofstream fout(file_name, ios::binary | ios::app);
		cout << "write: " << sizeof(obj) << endl;
		if (fout.write((char*)&obj, sizeof(obj)))
		{
			cout << "Manager Registered successfully" << endl;
		}
		fout.close();
	}
	void write(string file_name, admin obj)
	{
		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&obj, sizeof(obj));
		fout.close();
	}
	//void writeprod()
	//{

	//	ofstream fbout("inventory.dat", ios::binary | ios::app);
	//	if (!fbout)
	//	{
	//		cout << "Error!" << endl;
	//	}
	//	else
	//	{
	//		char wish = 'y';
	//		while (wish == 'y')
	//		{
	//			cout << "ID: "; cin >> al.prod_id;
	//			cout << "Name: "; cin >> al.prod_name;
	//			cout << "Category:"; cin >> al.prod_categ;
	//			cout << "Quantity: "; cin >> al.prod_quan;
	//			cout << "  Price   : "; cin >> al.prod_price;

	//			fbout.write((char*)&al, sizeof(al));
	//			cout << "Want to add more," << endl;
	//			cin >> wish;
	//		}
	//		//fbout.close();
	//	}
	//	fbout.close();
	//	system("cls");
	//}
	//void searchprod()
	//{
	//	string id1;
	//	system("cls");

	//	heading("Welcome to Inventory");


	//	cout << "Search the product by its ID: " << endl;
	//	cin >> id1;
	//	int srch = 0;

	//	ifstream filein("inventory.dat", ios::in | ios::binary);

	//	while (filein.read((char*)&al, sizeof(al)))
	//	{

	//		// << "Id" << "\t" << "Name" << "\t" << "Category" << "\t" << "Quantity" << "\t" << "Price: " << endl;

	//		//if (id1 == al.prod_id)
	//		//{

	//					srch = 1;
	//			//{
	//			cout << "Id" << "\t" << "Name" << "\t" << "Category" << "\t" << "Quatity" << "\t" << "Price: " << endl  ;
	//			cout << endl;
	//			al.dis();
	//		//	break;
	//		

	//		
	//	}
	//	filein.close();
	//	if (srch == 0)
	//	{
	//		cout << "Prod not found,....\n";
	//	}
	//	int ans = 0;
	//	cout << "Press 1 to Go Back : ";
	//	cin >> ans;
	//	system("CLS");
	//	ans = 1;
	//	system("cls");
	//}
	//filein.close();

	/*if (srch == 0)
	{
		cout << "No,Product Found : " << endl;
	}*/




	/*void read(string file_name) {
		admin obj(" ", " ");
		ifstream fin(file_name, ios::binary);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			obj.display();
		}

		fin.close();
	}*/


	void registermanager()
	{
		manager a;
		heading("Making Manager Account");
		string s;
		system("cls");

		cout << "NAME: ";

		cin >> s;
		strcpy_s(a.man_name, 20, s.c_str());
		cout << "CNIC: " << endl;
		cin >> s;
		strcpy_s(a.man_cnic, 20, s.c_str());
		//cout << "Enter Username:  " << endl;
		cout << "Username: " << endl;

		cin >> s;
		strcpy_s(a.man_user, 20, s.c_str());
		cout << username << "," << sizeof(username);
		cout << "Password: " << endl;


		cin >> s;
		strcpy_s(a.man_pass, 20, s.c_str());
		cout << "City to which it is assigned" << endl;

		cin >> s;
		//strcpy_s(a.store, 4, s.c_str());
		//cout << "LOCATION: " << endl;

		//cin >> s;

		write("manager.dat", a);

	}
	//void personal1()
	//{
	//	cout << "YOUR NAME : " <name << endl;

	//	cout << "CNIC: " << cnic << endl;

	//	cout << "Your username : " << username << endl;

	//	cout << "Your password : " << password << endl;
	//}
	void showallmanagers()
	{
		manager aa;
		int flag = 0;
		
		cout << "SEE DETAILS OF THE MANAGER: " << endl<<endl<<endl;
		//filein.close();
		fstream filein;
		filein.open("manager.dat", ios::binary | ios::in | ios::out);

		//		cout*/ //<< "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Name" << "\t\t" << "CNIC" << "\t\t" << "username" << "\t\t" << "paswword" << endl;
		cout << "--------------------------------------------------------------------------" <<endl;// << "\t" << "Price: " << endl;
		while (!filein.eof())
		{
			filein.read((char*)&aa, sizeof(aa));
			if (!filein.eof())
			{
				if (filein.tellg() < 0)
				{
					flag = 0; break;
				}
				cout << aa.man_name << "\t\t" << aa.man_cnic <<" \t\t" << aa.man_user  <<"\t\t\t" << aa.man_pass << endl; 
				
			}

		}
		int ans = 0;
		cout << "Press 1 to Go Back : ";
		cin >> ans;
		system("CLS");
		ans = 1;
		system("cls");

	}
	void asd()
	{
		manager aa;
		cout << "Name" << "\t\t" << "CNIC" << "\t\t" << "username" << "\t\t" << "paswword" << endl;
		cout << aa.man_name << "\t\t" << aa.man_cnic << " \t\t" << aa.man_user << "\t\t\t" << aa.man_pass << endl; 

	}
	void manager_display_data() {
		/*cout << "Username: " << this->username << endl;

		cout << "password: " << this->password << endl;

		cout << "NAME: " << name << endl;

		cout << "CNIC: " <<cnic;*/
		string cnic1;
		system("CLS");
		manager s;

		cout << "Welcome to Manager Detail Menu" << endl << endl;

		cout << "Enter manager cnic : ";

		cin >> cnic1;
		cout << endl << endl;
		string d_name;
		int flag = 0;
		int srch = 0;

		ifstream filein("manager.dat", ios::in | ios::binary);

		while (filein.read((char*)&s, sizeof(s))) {

			//string temp1(cnic);

			//if (cnic1 == temp1) {
			if (cnic1 == s.man_cnic)
			{
				//	//personal1();
				//	srch = 1;
				cout << "NAME :" << s.man_name << endl;

				cout << "CNIC :" << s.man_cnic << endl;

				cout << "username :" << s.man_user << endl;

				cout << "Password : " << s.man_pass << endl;

				cout << "Stor Assigned: " << s.store << endl;
				//cout << "Store assigned: " << this->stores[1] << endl;
				//cout << "Your Balance : " << this->pat_balance << endl;
				break;
				flag++;
			}

		}
			filein.close();
			if (flag == 0)
			{
				cout << "NO RECOED" << endl;
			}
			cout << endl;
			int ans = 0;
			cout << "Press 1 to Go Back : ";
			cin >> ans;
			system("CLS");
			ans = 1;
		
	}

	void edit_manger()
	{
		int flag = 0;
		string id1;
		manager sl;
		fstream out;
		int pos;
		out.open("manager.dat", ios::in | ios::out | ios::binary);
		//	int id1;


		cout << "Enter the manager cnic to modify tha data" << endl;
		
		cin >> id1;

		while (out.read((char*)&sl, sizeof(sl)))
		{
			if ( sl.man_cnic ==id1)
			{
				pos = out.tellg();

				//	sl.dd();


				cout << "Enter new record details: " << endl;

				cout << sl.man_name << "\t\t" << sl.man_cnic << " \t\t" << sl.man_user << "\t\t\t" << sl.man_pass << endl; ;

				out.seekg(pos - sizeof(sl));//Position Pointer

				cout << "CNIC : "; cin >> sl.man_cnic;

				cout << "Name : "; cin >> sl.man_name;

				cout << "UserName :"; cin >> sl.man_user;

				cout << "Password : "; cin >> sl.man_pass;

				//cout << "Measured Units :"; cin >> sl.measured_unit;

				out.write((char*)&sl, sizeof(sl));


				flag++;

				break;
			}
			//out.close();
		}
		out.close();
		if (flag == 0)
		{
			cout << "No record found " << endl;
		}
		int ans = 0;
		cout << "Press 1 to Go Back : ";
		cin >> ans;
		system("CLS");
		ans = 1;
		system("cls");
	}
	void showallcustomerss()
	{
		customer aa;
		int flag = 0;
		
		cout << "SEE DETAILS OF THE CUSTOMERS : " << endl << endl << endl;
		//filein.close();
		fstream filein;
		filein.open("customer.dat", ios::binary | ios::in | ios::out);

		//		cout*/ //<< "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Name" << "\t" << "CNIC" << "\t" << "username" << "\t" << "paswword"<<"\t"<<"Mail"<<"\t"<<"Gender"<<"\t"<<"PHONE NO."<<"\t" << "Address" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;// << "\t" << "Price: " << endl;
		while (!filein.eof())
		{
			filein.read((char*)&aa, sizeof(aa));
			if (!filein.eof())
			{
				if (filein.tellg() < 0)
				{
					flag = 0; break;
				}
				cout << aa.name << "\t" << aa.cnic << " \t" << username << "\t" << password << "\t" << aa.email << "\t" << aa.gender << "\t" << aa.phonenum << "\t" << aa.address << endl << endl; 

			}

		}
		int ans = 0;
		cout << "Press 1 to Go Back : ";
		cin >> ans;
		system("CLS");
		ans = 1;
		system("cls");

	}
	void remove_spam()
	{

		int flag = 0;
		customer qwe;
		string idd;

		ifstream fin;
		fin.open("customer.dat", ios::in | ios::binary);
		ofstream fbout("cust.dat");
		ofstream fbout2("trashman1.dat", ios::app);

		cout << "Enter the cnic  to remove  account " << endl;

		cin >> idd;

		cout << "Name" << "\t" << "CNIC" << "\t" << "username" << "\t" << "paswword" << "\t" << "Mail" << "\t" << "Gender" << "\t" << "PHONE NO." << "\t" << "Address" << endl;
		while (fin.read((char*)&qwe, sizeof(qwe))) {

			if (idd == qwe.cnic)
			{
				cout << "Following account  will be removed........" << endl;


				cout << qwe.name << "\t" << qwe.cnic << " \t" << username << "\t" << password << "\t" << qwe.email << "\t" << qwe.gender << "\t" << qwe.address << endl;

				flag++;


				fbout2.write((char*)&qwe, sizeof(qwe));
			}
			else
			{
				fbout.write((char*)&qwe, sizeof(qwe));

			}
		}
		fin.close();
		fbout.close();
		fbout2.close();
		if (flag == 0) {
			cout << "No Such account in a record: " << endl;
		}

		remove("customer.dat");
		rename("cust.dat", "customer.dat");
		cout << "Press any key to go back: " << endl;
		_getch();
		system("cls");
	}
	
	//void update_manager_location()
	//{
	//	int s = 0;
	//	long pos;
	//	manager g;
	//	int temp=0;
	//	string cni;
	//	cout << "Enter the cnic of thr manager: " << endl;
	//	cin >> cni;
	//	fstream filein("manager.dat", ios::in | ios::binary | ios::out);
	//	while (temp == 0)
	//	{
	//		while (filein.read((char*)this, sizeof(this))) {

	//			string t1(cnic);
	//			if (cni == t1)
	//			{
	//				/*s = 1;
	//				cout << "NAME :" << name << endl;

	//				cout << "CNIC :" << cnic << endl;

	//				cout << "username :" << username << endl;

	//				cout << "Password : " << password << endl;

	//				cout << "Stor Assigned: " << stores << endl;*/

	//				cout << "Enter new store loaction: " << endl;

	//				cout << "Choose between   1-Rawalpindi    2-Islamaad    3-Karachi     4- Lahore" << endl;

	//				cin >> stores;

	//				int t = filein.tellg();
	//				int s = sizeof(*this);
	//				
	//				filein.seekp(t - s, ios::beg);

	//				write("manager.dat", *this);
	//				filein.close();
	//				cout << "Enter 1" << endl;
	//				cin >> temp;
	//				system("cls");
	//				break;
	//			}

	//		}
	//		//filein.close(
	//	}
	// 
	
	void delete_manager()
	{
		int flag = 0;
		manager qwe;
		string idd;

		ifstream fin;
		fin.open("manager.dat", ios::in | ios::binary);
		ofstream fbout("man.dat");
		ofstream fbout2("trashman.dat", ios::app);

		cout << "Enter the cnic  to fire  manager" << endl;

		cin >> idd;


		while (fin.read((char*)&qwe, sizeof(qwe))) {

			if (idd == qwe.man_cnic)
			{
				cout << "Following manager will be fired........" << endl;

				
				cout << qwe.man_name << "\t\t" << qwe.man_cnic << " \t\t" << qwe.man_user << "\t\t\t" << qwe.man_pass << endl;

				flag++;

				fbout2.write((char*)&qwe, sizeof(qwe));
			}
			else
			{
				fbout.write((char*)&qwe, sizeof(qwe));

			}
		}
		fin.close();
		fbout.close();
		fbout2.close();
		if (flag == 0) {
			cout << "No Such manager in a record: " << endl;
		}

		remove("manager.dat");
		rename("man.dat", "manager.dat");
		cout << "Press any key to go back: " << endl;
		_getch();
		system("cls");
	}


	void show_feedback()
	{
		feedback s;
 	fstream filein;
	int flag = 0;
		filein.open("feedback.dat", ios::binary | ios::in | ios::out);
		//cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;// << "\t" << "Price: " << endl;
		cout << "User Name: " << "						" << "FeedBack Provided : " << endl;
		while (!filein.eof())
		{
			filein.read((char*)&s ,sizeof(s));
			if (!filein.eof())
			{
				if (filein.tellg() < 0)
				{
					flag = 0; break;
				}
				cout << username << "\t\t\t\t\t\t\t\t" << s.temp << endl;// << aa.cnic << " \t" << username << "\t" << password << "\t" << aa.email << "\t" << aa.gender << "\t" << aa.phonenum << "\t" << aa.address << endl << endl;

			}

		}
		int ans = 0;
		cout << "Press 1 to Go Back : ";
		cin >> ans;
		system("CLS");
		ans = 1;
		system("cls");
	}

	void remove_feedback()
	{

		int flag = 0;
		feedback qwe;
		char idd[130];

		ifstream fin;
		fin.open("feedback.dat", ios::in | ios::binary);
		ofstream fbout("feed1.dat");
		ofstream fbout2("feedtrashman1.dat", ios::app);

		cout << "Enter the name of the user whom feedback is  to removed  " << endl;

		cin >> idd;

		cout << "Name" << "\t" << "CNIC" << "\t" << "username" << "\t" << "paswword" << "\t" << "Mail" << "\t" << "Gender" << "\t" << "PHONE NO." << "\t" << "Address" << endl;
		while (fin.read((char*)&qwe, sizeof(qwe))) {

			if (strcmp(username,idd) == 0)
			{
				cout << "Following feedback  will be removed........" << endl;
				cout << "User Name: " << "						" << "FeedBack Provided : " << endl<<endl;
				cout << username << "\t\t\t\t\t\t\t\t" << qwe.temp << endl;
				//cout << qwe.name << "\t" << qwe.cnic << " \t" << username << "\t" << password << "\t" << qwe.email << "\t" << qwe.gender << "\t" << qwe.address << endl;

				flag++;


				fbout2.write((char*)&qwe, sizeof(qwe));
			}
			else
			{
				fbout.write((char*)&qwe, sizeof(qwe));

			}
		}
		fin.close();
		fbout.close();
		fbout2.close();
		if (flag == 0) {
			cout << "No Such account in a record: " << endl;
		}

		remove("feedback.dat");
		rename("feed1.dat", "feedback.dat");
		cout << "Press any key to go back: " << endl;
		_getch();
		system("cls");
	}
};

