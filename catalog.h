#pragma once

#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class catalog {
public:
	int prod_id; char prod_name[15], prod_categ[15]; char measured_unit[10];
	int prod_price;
	int  prod_quan ;
	//string da[10] = { "Bread" };
	//public:
	 catalog() {}
	int getid()
	{
		return prod_id;
	}
	int get_quan()
	{
		return prod_quan;
	}
	int price()
	{
		return prod_price;
	}
	char* prodname()
	{
		return prod_name;
	}
	 catalog(int id, string name1, string categ1, int quantity1, int price, string measure)
	{
		//strcpy_s(prod_id, id.c_str());
		strcpy_s(prod_name, name1.c_str());
		strcpy_s(prod_categ, categ1.c_str());
		//strcpy_s(prod_quan, quantity1.c_str());
		strcpy_s(measured_unit, measure.c_str());
		prod_id = id;
		prod_price = price;
		prod_quan = quantity1;

	}
	void display_prod()
	{
		//cout << "Product Found" << endl;

		//cout << "Id" << "\t" << "Name" << "\t" << "Category" << "\t" << "Quantity" << "\t" << "Price " << "Units " << endl << endl;

		cout <<"\t" << prod_id << "\t\t" << prod_name << "\t\t" << prod_categ << "\t\t\t"  << prod_price << "\t\t" << measured_unit<<"\t\t"<< prod_quan << endl << endl;
	}
	void dd()
	{
		cout << "\t" << "Id" << "\t\t" << "Name" << "\t\t" << "Category" << "\t\t" << "Price " << "\t\t" << "Units "<< "\t\t" <<"Quantity" << endl
			;
			cout << "\t" << prod_id << "\t\t" << prod_name << "\t\t" << prod_categ << "\t\t\t" << prod_price << "\t\t" << measured_unit<< "\t\t"<<prod_quan << endl << endl;
	}
	void add_prod()
	{
		catalog k1;
		ofstream fbout("catalog.dat", ios::binary | ios::app);
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
			//	fbout.close();
				cout << "Want to add more," << endl;
				cin >> wish;
			}
		}
		fbout.close();
	}

	void with(int qnt)
	{
		catalog a;
		if (prod_quan >= qnt)
		{
			prod_quan -= qnt;
		}
		else
			cout << "Insufficent stock" << endl;
	}

	void show_prod()
	{
		catalog a1;
		//int id1;

		system("cls");


		int flag = 0;
		cout << "Welcome to the inventory " << endl;

		//int srch = 0;

		//in >> id1;
		fstream filein;
		filein.open("catalog.dat", ios::binary | ios::in | ios::out);

		cout << "\t" << "Id" << "\t\t" << "Name" << "\t\t" << "Category" << "\t\t" << "Price " << "\t\t" << "Units " << "\t\t" << "prod_quan" << endl;

		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		while (!filein.eof())
		{
			filein.read((char*)&a1, sizeof(a1));
			if (!filein.eof())
			{
				if (filein.tellg() < 0)
				{
					flag = 0; break;
				}
				a1.display_prod();
			}
		}
		//filein.close();
		//filein.close();
			/*int ans = 0;
			cout << "Press 1 to : ";
			cin >> ans;
			system("CLS");
			ans = 1;
			system("cls");*/

		int ans = 0;
		cout << "Press 1 to Go Back : ";
		cin >> ans;
		system("CLS");
		ans = 1;
		system("cls");
	}
	int get_price_from_file(int n)
	{
		catalog bb1;
		int r = 0;
		 int id = n;
		 ifstream fin;
		 fin.open("catalog.dat", ios::in);
			 while (fin.read((char*)&bb1, sizeof(bb1)))
			 {
				 if (id == bb1.getid())
				 {
					 r = bb1.price();
				 }

		     }
			 fin.close();
			 return r;
	}
	char* get_name_from_file(int n)
	{
		catalog s;
		int id = n;
		char nm[15] = "none";
		ifstream fin;
		fin.open("catalog.dat", ios::in);
		while (fin.read((char*)&s, sizeof(s)))
		{
			if (n == s.getid())
			{
				strcpy_s(nm, s.prodname());
			}
		}
		fin.close();
		return nm;
	}
	void edit_prod()
	{
		int flag=0;
		int id1;
		catalog sl;
		fstream out;
		int pos;
		out.open("catalog.dat", ios::in | ios::out | ios::binary);
	//	int id1;


		cout << "Enter the product id to modify tha data" << endl;
		cin >> id1;

		while (out.read((char*)&sl, sizeof(sl)))
		{
			if (id1 == sl.getid())
			{
				pos = out.tellg();

			//	sl.dd();

				
				cout << "Enter new record details: " << endl;
				
				sl.dd();
				
				out.seekg(pos - sizeof(sl));//Position Pointer
				
				cout << "ID : "; cin >> sl.prod_id;
				
				cout << "Name : "; cin >> sl.prod_name;
				
				cout << "Category :"; cin >> sl.prod_categ;
				
				cout << "Price : "; cin >> sl.prod_price;
				
				cout << "Measured Units :"; cin >> sl.measured_unit;
				
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
	void delete_prod()
	{
		int flag = 0;
		catalog qwe;
		int idd;
		ifstream fin;
		fin.open("catalog.dat", ios::in | ios::binary);
		ofstream fbout("temp.dat");
		ofstream fbout2("trash.dat", ios::app);
		cout << "Enter the product id to modify tha data" << endl;
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

		remove("catalog.dat");
		rename("temp.dat", "catalog.dat");
		cout << "Press any key to go back: " << endl;
		_getch();
		system("cls");
	}
	
};