#pragma once

#include"catalog.h"

#include<iostream>

using namespace std;

class inventory :public catalog
{
public:
	inventory(){}

	void write(string file_name, inventory obj)
	{
		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&obj, sizeof(obj));
		fout.close();
	}
	void transfer()
	{
		catalog qwe;
	
		ifstream fin;
		fin.open("catalog.dat", ios::in | ios::binary);

		ofstream fbout2("inventory.dat", ios::app);

		while (fin.read((char*)&qwe, sizeof(qwe))) {

			fbout2.write((char*)&qwe, sizeof(qwe));
		}


		fin.close();

		fbout2.close();

	}
	void display_prod1()
	{
		//cout << "Product Found" << endl;

		//cout << "Id" << "\t" << "Name" << "\t" << "Category" << "\t" << "Quantity" << "\t" << "Price " << "Units " << endl << endl;

		cout << "\t" << prod_id << "\t\t" << prod_name << "\t\t" << prod_categ << "\t\t\t" << prod_price << "\t\t" << measured_unit << "\t\t" << prod_quan
			<< endl << endl;
	}
	void show_prod()
	{
	inventory a;
		//int id1;

		system("cls");



		cout << "Welcome to the inventory " << endl;

		//int srch = 0;

		//in >> id1;
		fstream filein;
		filein.open("inventory.dat", ios::binary | ios::in | ios::out);

		cout << "\t" << "Id" << "\t\t" << "Name" << "\t\t" << "Category" << "\t\t" << "Price " << "\t\t" << "Units " << "\t\t" << "Quantity" << endl;

		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		while (filein.read((char*)&a, sizeof(a)))
		{

			a.display_prod1();

		}

		int ans = 0;
		cout << "Press 1 to Go Back : ";
		cin >> ans;
		system("CLS");
		ans = 1;
		system("cls");


	}
	void add_quantity()
	{
		int flag = 0;
		int id11;
		inventory x1;
		int g;
		///catalog x1;
		fstream out1;
		out1.open("inventory.dat", ios::in | ios::out | ios::binary);
		int pos;
		//out.open("inventory.dat", ios::in | ios::out | ios::binary);
		//	int id1;


		cout << "Enter the product id to modify tha data" << endl;

		cin >> id11;

		while (out1.read((char*)&x1, sizeof(x1)))
		{
			if (id11 == x1.getid())
			{
				pos = out1.tellg();

				x1.dd();

				cout << "Enter new record details............... " << endl;

				out1.seekg(pos - sizeof(x1));//Position Pointer

				cout << "Quantity : "; cin >> x1.prod_quan;
				
				out1.write((char*)&x1, sizeof(x1));
				
				flag++;
				break;
			}
			//out1.close();
		}
		out1.close();
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

	void _add_items()
	{
		inventory k1;
		ofstream fbout("inventory.dat", ios::binary | ios::app);
		if (!fbout)
		{
			cout << "Error!" << endl;
		}
		else
		{
			char wish = 'y';
			while (wish == 'y')
			{
				cout << "ID : "; cin >> k1.prod_id;
				cout << "Name : "; cin >> k1.prod_name;
				cout << "Category :"; cin >> k1.prod_categ;
				cout << "Price : "; cin >> k1.prod_price;
				cout << "Measured Units :"; cin >> k1.measured_unit;
				//cout << "  ";cin >> prod_price;
				cout << "Product Quantity :"; cin >> k1.prod_quan;

				fbout.write((char*)&k1, sizeof(k1));
				cout << "Want to add more," << endl;
				cin >> wish;
			}
		}
	}
	void delete_items()
	{

		int flag = 0;
		inventory qwe;
		int idd;
		ifstream fin;
		fin.open("inventory.dat", ios::in | ios::binary);
		ofstream fbout("temp1.dat");
		ofstream fbout2("trash1.dat", ios::app);

		cout << "Enter the product id to delete tha data" << endl;
		
		cin >> idd;


		while (fin.read((char*)&qwe, sizeof(qwe))) {

			if (idd == qwe.getid())
			{
				cout << "Following reocord will be deleted........" << endl;
				
				qwe.dd();

				
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
			cout << "No Such Product in a record: " << endl;
		}

		remove("inventory.dat");
		rename("temp1.dat", "inventory.dat");
		cout << "Press any key to go back: " << endl;
		_getch();
		system("cls");
	}
}

;


