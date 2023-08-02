#pragma once
#include"Header.h"
#include"costumer.h"
#include"Admin.h"
#include"manager.h"
#include"feedback.h"
#include"inventory1.h"
#include"csrt.h"
#include<iostream>
using namespace std;

int main()
{
	int choice;
	string name1, n1;
	admin c("ibo", "123");
	c.write("admin.dat", c);
	customer kk11(name1);
	manager m11;

m1:
	cout << endl;
	cout << endl;
	cout << setw(78) << "	   WELCOME TO SHOPIFY ONLINE STORE												\n\n \n";
	cout << endl;

		//print();
		cout<< setw(65) << "1- Choose as Admin(login):" << endl


		<< setw(64) << "2- Costumer Registraton: " << endl


		<< setw(56) << "3- MANAGER LOGIN:" << endl;

	cout << setw(65) << "--------------------------------------------------------------------------------------------------------------------" << endl;
	//print();

	cin >> choice;

	switch (choice)
	{
	case 1:

		c.Login();
		_getch();
		break;


	case 2:


		cout << "1-Signup:" << endl;

		cout << "2- LOGIN: " << endl;
		int n;
		cin >> n;

		switch (n)
		{
		case 1:

			kk11.registeration();

			_getch();
			break;
			//goto m1;

		case 2:
			kk11.Login();
			_getch(); break;
			//goto m1;
		}
		break;
	case 3:
		m11.Login();
		break;
	}
	system("cls");
	goto m1;





	return 0;
}
