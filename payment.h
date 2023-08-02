#pragma once
#include"Header.h"
#include"feedback.h"
#include<iomanip>
#include<iostream>

using namespace std;

class payment :public user
{
public:

	void pay()
	{
		feedback l;
		char n='0';
		user a;
		int choice;
		cout << setw(25) << endl;
		cout << "Please Choose your payment method: " << endl;
		cout << "1-EasyPaisa : " << endl;
		cout << "2-JazzCash   : " << endl;
		cout << "3-Bank Transfer: " << endl;
		cout << "4-Cash on delievery: " << endl;
		
		cout << "Please choose from above : " << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			//cout.setf(ios::right);
			cout << setw(25);
			cout<<"---------------Welcome to easypaisa menu------------" << endl;

			cout  << "UserName: " << endl
				; cin >> username;
			cout << " Pasword: " ;
			cin >> password;
			cout << "Account Found: " << endl;

			cout << "Press 1 to pay: " << endl;
			cin >> n;
			
			cout << "Payment Successfull:" << endl;
			
			l.feedback1();

			break;
		
		case 2:



			cout << "UserName: " << endl;
			cin >> username;
			cout << "Pawword: " << endl;
			cin >> password;

			cout << "Press 1 to pay: " << endl;
			cin >> n;
			if(n=='1')
			
				cout << "Payment Successfull:" << endl;
			l.feedback1();
			break;
		case 3:
			cout << "CardNo.: " << endl;
			cin >> username;
			cout << "Pawword: " << endl;
			cin >> password;

			cout << "Press 1 to pay: " << endl;
			cin >> n;
			if (n == '1')
			cout << "Payment Successfull:" << endl;
			l.feedback1();
			break;
		case 4:
			cout << "Rs 30 will be added to your balance: " << endl;

			cout << "Press 1. to proceed: " << endl;
			cin >> n;
			if (n == 1)
			cout << "Ordered Confirmed: " << endl;
		


			l.feedback1();
			break;

		}
	}
};