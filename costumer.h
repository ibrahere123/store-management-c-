#pragma once
#include"Header.h"
#include"inventory1.h"
#include"csrt.h"
#include"catalog.h"
#include<iostream>
#include<fstream>
using namespace std;
class customer:public user
{

public:
	char name[100], email[100], address[100];

	char cnic[100];
	char phonenum[100];
	
	int age;
	
	char gender;

//public:

	customer() {};
	//{
		//age = 0;
	
		
	//}
	customer(string pass, string user):user(username,password )
	 {

		
		strcpy_s(username, user.c_str());
		//strcpy_s(cnic, b.c_str());
		strcpy_s(password, pass.c_str());
	}

	customer(string name1, string cnic1, string mail, string aadress, string setpas1,string phone1) :user(username, password) {

		strcpy_s(name, name1.c_str());
	//strcpy_s(cnic, cnic1.c_str());
		strcpy_s(email, mail.c_str());
		strcpy_s(address, aadress.c_str());
		//strcpy_s(password, setpas1.c_str());
		strcpy_s(phonenum, phone1.c_str());
	}
	customer(string u) {
		strcpy_s(username, u.c_str());
	}
	void home()
	{
		 
		
	//	billdetails n;
		customer g;
		
		bool go = true;
		int ans;
		cart b;
		while (go)
		{
			system("cls");

			heading("HOME");
			cout <<"\t) You want to:\n"
				<< "\t1) Buy goods\n"
				<< "\t2) Log Out\n"
				<< endl;

			cout << "\n Your choice > ";
			cin >> ans;
			switch (ans)
			{
			case 1:
				b.order(); system("cls");
				home(); break;
			case 2:
				go = false;
				cout << "You have been logged out: " << endl;
				break;
				//cout << "You have been logged out: " << endl;
			}
		}
	}
	void registeration()
	{
		customer al;
		bool agecheck = false, cniccheck = false, mailcheck = false, phonecheck = false;
		bool gendercheck = false, checkpass = false;
		cout << "NAME :";

		cin >> al.name;
		//swhile (agecheck==false)
			cout << "AGE: ";
		cin >> al.age;
		
		cout << endl;

		while (agecheck == false)
		{
			cout << "Confirm AGE :" << endl;

			cin >> al.age;
			
			agecheck = true;
			
			if (age < 12 && age>99)
				agecheck = false;
			{
				cout << "Please enter age between 12 and 99 " << endl;
			}
		
		}


		cout << "username: ";

		cin >> al.username;
		
		

		while (checkpass == false) {

			
			cout << "Password" << endl;
			cout << "Password must be 8 characters long and the use of a minimum of one special character, uppercase, lowercase, and the numeric digit is a must." << endl;
			cin >> al.password;

			if (strlen(al.password) < 9) {
				checkpass = false;
				cout << "Your password must be atleast 9 characters long" << endl;
				continue;
			}
			for (int i = 0; i < 10; i++) {
				if ((al.password[i] >= 65 &&al. password[i] <= 90) || (al.password[i] >= 97 &&al. password[i] <= 122) || (al.password[i] >= 32 && al.password[i] <= 47) ||
					(al.password[i] >= 58 && al.password[i] <= 64) ||
					(al.password[i] >= 91 && al.password[i] <= 96) ||
					(al.password[i] >= 123 &&al. password[i] <= 126)) {
					checkpass = true;
					continue;
				}
			}
		}

		cout << endl;

		

		cout << "CNIC: ";
		cin >> al.cnic;
		while (cniccheck == false)
		{
			cout << "CNIC. ";
			cin >> al.cnic;
			cniccheck = true;

			if (strlen(al.cnic) != 14)
			{
				phonecheck = false;

				cout << "Please enter the correct cnic ";
			}
		}

		cout << "PHONE N0.(11 Digits)" << endl;

		cin >> al.phonenum;
		while (phonecheck == false)
		{
			cout << "Phone No. ";
			cin >> al.phonenum;
			phonecheck = true;

			if (strlen(al.phonenum) != 12)
			{
				phonecheck = false;

				cout << "Please enter the correct phone number ";
			}
		}
		bool found=false;
		cout << "MAIL: ";
		cin >> al.email;
		cout << endl;
		while (mailcheck == false)
		{
			cout << "MAIL: ";
			cin >> al.email;

			cout << endl;

			mailcheck = true;
			for (const char& c :al. email)
			{
				if (c == '@')
				{
					found = true;
					mailcheck = true;
					break;
				}
			}

			if (!found)
			{


				cout << " Email address must contain a '@'\n";


				mailcheck=false;
			}
		}
		cout << "GENDER: ";
		cin >> al.gender;
		cout << endl;
		while (gendercheck == false)
		{
			cout << "Gender: ";
			
			cin >> al.gender;
			gendercheck = true;
			if (al.gender != 'M' && al.gender != 'm' && al.gender != 'F' &&al. gender != 'f')
			{
				gendercheck = false;
				cout << "Please! enter correct gender: " << endl;
				
			}
		}
		cout << "ADDRESS: ";
		cin >> al.address;
		cout << endl;
		  

		cout << "Account Created Successfully : ";

		write("customer.dat", al);
		home();
	}

	void write(string file_name, customer obj)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&obj, sizeof(obj));
		fout.close();

	}
	
	

	void read(string file_name) {
		customer objss;
		ifstream fin(file_name, ios::binary);
		while (fin.read((char*)&objss, sizeof(objss)))
		{
			objss.Display();
		}
		fin.close();
	}

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
			customer data;
			//read("manager.dat", user, pass);
			//home();
			bool flag = false;
			long pos;
			ifstream filein("customer.dat", ios::binary);


			//filein.seekg(0);

			while (filein.read((char*)&data, sizeof(data))) {
				//cout << "read: " << sizeof(data) << endl;
				//pos = filein.tellg();
				//string temp1(data.username);
				//string temp2(data.password);
				//c//out << data.man_user << ", " << data.man_pass << endl;
				cout << data.username << "," << data.password << endl;
				if (user == data.username && pass == data.password) {
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

	void Display() {
		customer s;
		cout << "Username: " << s.username << endl;
		cout << "password: " << s.password << endl;
	}


};


