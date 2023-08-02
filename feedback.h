#pragma once
#include"Header.h"
#include<iostream>

#include<fstream>
#include<iomanip>
using namespace std;
class feedback:public user

{
public:
	char temp[100];
	
	feedback() {}

	 void feedback1()
	{
		 feedback g;
		 string s;
		
		//fio.out("Feedback.dat", ios::out, ios::binary);
		ofstream fbout("feedback.dat", ios::binary | ios::app);
		if (!fbout)
		{
			cout << "Error!" << endl;
		}
		else
		{
			//char wish = 'y';
			//while (wish == 'y')

				//cout << "ID : "; cin >> k1.prod_id;
			cout <<setw(25) << "WELCOME TO FEEDBACK MENU: " << endl;
			
			cout << "UserName : "; cin >> username;

			cout << "PROVIDE FEEDBACK: " << endl;

			cin >> s;
			strcpy_s(g.temp,100, s.c_str());

			fbout.write((char*)&g, sizeof(g));
			//fbout.close();
		}
		fbout.close();
		//fbout.close();
	}
	




	
};
