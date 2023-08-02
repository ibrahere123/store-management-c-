#pragma once
#include"inventory1.h"
#include"Header.h"
//#include"csrt.h"
#include"feedback.h"
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class manager :public user
{
public:
	char man_user[20], man_pass[20], man_cnic[20];
	char man_name[20];
	char store[4];


	manager() {}
	manager(string n)
	{
		strcpy_s(username, n.c_str());
	}

	manager(string user, string pass2):user(username,password)
	{
		strcpy_s(username, user.c_str());
		strcpy_s(password, pass2.c_str());



	
	}

	void home()
	{
		feedback ll;
	
		//billdetails d;
		//mananger rt;
		inventory add1;
		//cart x;
		bool go = true;
		int ans;

		while (go)
		{
			system("cls");

			heading("HOME");
			cout<< " You want to:\n"
				<< "\t1) Buy goods\n"
				<< "\t2) Show Inventory\n"
				<< "\t3) View Your Profile\n"
				<< "\t5) Edit/Add Quantity\n"
				<< "\t6) Add Items\n"
				<< "\t7) Delete Items" << endl
			    <<"\t8)Logout" << endl;
			cout << "\n Your choice > ";
			cin >> ans;
			switch (ans)

			{
			case 1:
				//billdetails d;
			//	x.cart1();
				add1.transfer();
				 break;
			case 2:
				add1.show_prod();
				break;
			case 3:
                display();
				break;
			case 4:
			add1.show_prod(); break;
			case 5:
				add1.add_quantity(); break;
			case 6:
				add1._add_items(); break;
			case 7:
				add1.delete_items(); break;
			case 8:
				system("cls");

				cout << "You have been lgged out" << endl;
			
				go = false;
				break;
			}
		}
	}
	//void read(string file_name, string u, string p)
	//{a
	//	manager obj1;


	//	//ifstream fin(file_name, ios::binary);

	//	//while (fin.read((char*)&obj1, sizeof(obj1)))
	//	//{
	//	//	string a(obj1.username);
	//	//	string b(obj1.password);
	//	//	if (a == u && p == b)
	//	//	{
	//	//		cout << "Login Successful: " << endl;
	//	//		cout << endl;
	//	//		_getch();
	//	//		home();
	//	//		//home()
	//	//	}
	//	//	/*else {
	//	//		cout << "Login failed: " << endl;
	//	//	}*/
	//	//	else {
	//	//		cout << "LOGIN FAILED:" << endl;
	//	//	}
	//	//	//home();
	//	ifstream filein("manager.dat", ios::in | ios::binary);
	//	while (filein.read((char*)this, sizeof(*this))) {
	//		string temp1(this->cnic);
	//		if (temp1 == pass) {
	//		}
	//	}
	//	Login();
	//	//_getch();
	//	//home();

	//	fin.close();


	//}

	/*	void read(string file_name) {
			manager obj(" "," ");
			ifstream fin(file_name, ios::binary);
			while (fin.read((char*)&obj, sizeof(obj)))
			{
				obj.display();
			}
			fin.close();
		}*/

	//void showfeedback()
	//{
	//	int flag = 0;
	//	feedback a1;
	//	//int id1;

	//	system("cls");



	//	cout << "Welcome to FeedBack Menu  " << endl;

	//	//int srch = 0;

	//	//in >> id1;
	//	fstream filein;
	//	filein.open("feedback.dat", ios::binary | ios::in | ios::out);

	//	cout << "NAME: " << "			" << "FEEDBACK" << endl;
	//	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	//	while (!filein.eof())
	//	{
	//		filein.read((char*)&a1, sizeof(a1));
	//		if (!filein.eof())
	//		{
	//			if (filein.tellg() < 0)
	//			{
	//				flag = 0; break;
	//			}
	//			cout << username << "  " << temp << endl;
	//		}
	//	}
	//}
	void Login()
	{
		string user, pass;
		int temp = 0;
		while (temp == 0)
		{
			cout << "Enter Username:  " << endl;
			cin >> user;
			cout << endl;
			cout << "Enter Password: " << endl;
			cin >> pass;
			cout << endl;
			manager data;
			//read("manager.dat", user, pass);
			//home();
			bool flag = false;
			long pos;
			ifstream filein("manager.dat",  ios::binary);
			
			
			//filein.seekg(0);
			
			while (filein.read((char*)&data, sizeof(data))) {
				//cout << "read: " << sizeof(data) << endl;
				//pos = filein.tellg();
				//string temp1(data.username);
				//string temp2(data.password);
				//c//out << data.man_user << ", " << data.man_pass << endl;

				if (user == data.man_user && pass == data.man_pass) {
					//filein.seekg(pos);
					cout << "LOGIN SUCCESSFULL" << endl;
					flag = true;

					temp = 1;
					//_getch();
					//home();
					break;
				}
			}
			if (flag == false) {
				cout << "Login failed: " << endl;
				temp = 0;

			}
			filein.close();
		}
		system("cls");
		cout << "LOGIN SUCCESSFUL:  " << endl;
		
		_getch();
		
		home();
	}



	void personal()
	{
		cout << "USERNAME: " << man_user << endl;
		cout << "PASSWORD: " << man_pass << endl;
		cout << "NAME: " << man_name << endl;
		cout << "CNIC: " << man_cnic << endl;
	}
	



	void display() {
		/*cout << "Username: " << this->username << endl;

		cout << "password: " << this->password << endl;

		cout << "NAME: " << name << endl;

		cout << "CNIC: " <<cnic;*/
		string pass;
		system("CLS");
		cout << "Welcome to Manager Detail Menu" << endl << endl;

		cout << "Enter the cnic view your profile : ";
		manager g;
		cin >> pass;
		cout << endl << endl;
		string d_name;
		long pos;
		ifstream filein("manager.dat", ios::in | ios::binary);
		filein.seekg(0);
		while (filein.read((char*)&g, sizeof(g)))
		{ 
			pos = filein.tellg();
			//filein.read((char*)this, sizeof(*this));
				string temp1(g.man_cnic);
				if (temp1 == pass) {
					filein.seekg(pos);
					g.personal();
					//cout << "Your Balance : " << this->pat_balance << endl;
					break;
				}
			}

			filein.close();
			cout << endl;
			int ans = 0;
			cout << "Press 1 to Go Back : ";
			cin >> ans;
			system("CLS");
			ans = 1;

		}

	};
/*
	fstream fio("marks.dat", ios::in | ios::out);
	fio.seekg(0);
	while (!fio.eof())
	{
		pos = fio.tellg();
		fio.read((char*)&stud1, sizeof(stud1));
		if (stud1.getrno() == rno)
		{
			stud1.putdata();
			fio.seekg(pos);
			found = 't';
			break;
		}*/
