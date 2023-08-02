#pragma once
#include"inventory1.h"
#include"payment.h"
#include<iostream>
#include<fstream>
#include<chrono>
#include<ctime>
#include<Windows.h>
using namespace std;
using namespace chrono;
class cart:public payment
{
public:

	void disp()
	{
		int flag = 0;
		catalog a1;
		//int id1;

		system("cls");



		cout << "Welcome to the Shopify Store " << endl;

		//int srch = 0;

		//in >> id1;
		fstream filein;
		filein.open("inventory.dat", ios::binary | ios::in | ios::out);

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
	}
	//public:
	//
	//
	////	void with(int qnt)
	////{
	////		//inventory a;
	////		if (a.prod_quan >= qnt)
	////		{
	////			a.prod_quan -= qnt;
	////		}
	////		else
	////			cout << "Insufficent stock" << endl;
	////}
	//	void cart1()
	//	{
	//		int pos;
	//		inventory aa;
	//		cart x1;
	//		int i;
	//		int flag = 0;
	//		int qty;
	//		char wish;
	//		fstream s("inventory.dat", ios::binary | ios::out | ios::binary);
	//		do
	//		{
	//
	//			cout << "Enter the product id : " << endl;
	//
	//			cin >> i;
	//			cout << "Enter the amount of quantity : " << endl;
	//			cin >> qty;
	//			//fstream s("inventory.dat", ios::binary | ios::out | ios::binary);
	//
	//			while (s.read((char*)&x1, sizeof(x1)))
	//			{
	//				if (i == aa.getid())
	//				{
	//					pos = s.tellg();
	//					aa.with(qty);
	//
	//					s.seekg(pos - sizeof(aa));
	//
	//					s.write((char*)&aa, sizeof(aa));
	//					break;
	//					flag++;
	//				}
	//			}
	//			if (flag == 0)
	//			{
	//				cout << "no record: " << endl;
	//			}
	//			cout << "Do u want to continue: " << endl;
	//			cin >> wish;
	//		} 
	//		while (wish == 'y');
	//		s.close(); system("cls");
	//		_getch();
	//	
	//		aa.show_prod();
	//
	//		_getch();
	//	}
	//}
	//;
	void order()
	{
		payment op;
		//char/* cuffer[30];
		//ime_t rawtime;
		//struct tm* timeinfo;

		//time(&rawtime);
		//timeinfo = localtime_s(rawtime,30,cuffer);*/
		

		//printf("Current local time and date: %s", asctime(timeinfo));

		//time_t now = time(0);
		//// convert now to string form
		//time_t time(time_t *time);
		//char* date_time = time);

		int pos;
		inventory s;
		fstream open;
		int order_arr[50], quan[1000], c = 0;
		float amt, damt, total = 0;
		char ch = 'Y';
		cout << "\n============================";
		cout << "\n PLACE YOUR ORDER";
		cout << "\n============================\n";
		disp();

		do
		{
			cout << "\n\nEnter The Product No. Of The Product : ";
			cin >> order_arr[c];
			//	pos = open.tellg();
			cout << "\nQuantity in number : ";
			cin >> quan[c];
			c++;
			//open.seekg(pos - sizeof(s));
			cout << "\nDo You Want To Order Another Product ? (y/n)";
			cin >> ch;
			//open.write((char*)&s, sizeof(s));



		} while (ch == 'y' || ch == 'Y');
		cout << "\n\nThank You For Placing The Order";
		cout << "You are being directed to your cart: " << endl;
		
		cout << "Thank You for your patience: " << endl;
		
		
		system("cls");
		cout << "\n\n******************************** INVOICE ***************************************\n"<<endl;
		Sleep(3);
		get_time();
		cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAfter Discount\ n ";

		for (int x = 0; x <= c; x++)
		{

			open.open("inventory.dat", ios::in);
			open.read((char*)&s, sizeof(s));
			while (!open.eof())
			{
				if (s.prod_id == order_arr[x])
				{
					//	pos = open.tellg();
					amt = s.price() * quan[x]
						;
					//open.seekg(pos - sizeof(s));
					//open.write((char*)&s, sizeof(s));
					damt = amt - (amt * 0.8 / 100);//Discount awared to all customers
					cout << "\n" << order_arr[x] << "\t" << s.prodname() <<
						"\t" << quan[x] << "\t\t" << s.price() << "\t" << amt << "\t\t" << damt;


					total += damt;
				}
				open.read((char*)&s, sizeof(s));
			}

			open.close();
		}
		cout << "\n\n\t\t\t\t\tTOTAL = " << total<<"Rs.";
		
		_getch();
		cout << endl;
		cout << setw(26);
		op.pay();
	}
	void get_time()
	{
		struct tm newtime;
		__time32_t aclock;

		char buffer[32];
		errno_t errNum;
		_time32(&aclock);
		_localtime32_s(&newtime, &aclock);
		errNum = asctime_s(buffer, 32, &newtime);

		cout << "Order generated on:" << buffer << endl;
	}
	//	void with()
	//	{
	//		inventory st;
	//		fstream fio;
	//		system("cls");
	//		char temp[100]; int qty;
	//		int i = 0;
	//
	//		int q1;
	//		long pos = 0;
	//		//disp();
	//		do
	//		{
	//
	//			cout << "\n\nEnter the product's name \n" << endl;
	//			cin >> temp;
	//			cout << "\n\nEnter quantity: \n" << endl;
	//			cin >> qty;
	//			if (qty == 0)
	//				goto out;
	//			fio.open("inventory.dat", ios::binary | ios::out | ios::in);
	//			while (fio)
	//			{
	//				pos = fio.tellp();
	//				fio.read((char*)&st, sizeof(st));
	//				if (q1 == st.getid())
	//				{
	//
	//					st.withd(qty);
	//					fio.seekp(pos);
	//					fio.write((char*)&st, sizeof(st));
	//					i++; break;
	//				}
	//			}
	//		} while (qty != 0);
	//
	//		if (i != 1)
	//			cout << "\n\n!!Record not found!!";
	//	out:
	//		fio.close();
	//		cin.get();
	//		system("cls");
	//		disp();
	//		getch();
	//	}
	//	}
	//	void withd(int qty)
	//	{
	//		int amn;
	//		int damt;
	//		inventory a;
	//		if (a.get_quan() >= qty)
	//		{
	//			a.prod_quan-= qty;
	//			amn = a.price() * a.get_quan();
	//				
	//			//open.seekg(pos - sizeof(s));
	//			//open.write((char*)&s, sizeof(s));
	//			damt = amn - (amn * 0.8 / 100);//Discount awared to all customers
	//			cout << "\n" << order_arr[x] << "\t" << s.prodname() <<
	//				"\t" << quan[x] << "\t\t" << s.price() << "\t" << amt << "\t\t" << damt;
	//
	//
	//			total += damt;
	//			cout << "\n\nStock updated.\n";
	//			cout << "\n\nTotal price to be paid:" << a.price() * qty;
	//		}
	//		else
	//			cout << "\n\nInsufficient stock";
	//		getch();
	//
	//}
};