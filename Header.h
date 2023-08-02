#pragma once
#include<iostream>
using namespace std;
void heading(string h)
{
	cout << "ONLINE STORE: " << endl;
}
class user
{
protected:
	char password[20], username[20]; 
	
//	char cnic[20];
public:
	user()
	{}
	user(string name, string pass) {
	
		strcpy_s(username, name.c_str());
		strcpy_s(password, pass.c_str());
	
	}
	
	virtual void displaay()
	{
		cout << "WELCOME TO SHOPIFY STORE---------" << endl;
	}

};