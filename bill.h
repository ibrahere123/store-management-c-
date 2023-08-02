//#pragma once
//#include"catalog.h"
//#include<iostream>
//
//#include<iomanip>
//
//using namespace std;
//
//class bill:public catalog
//{
//protected:
//
//	int billno;
//public:
//
//	bill() {
//		billno = 0;
//	}
//	int getbillno() { return billno; }
//	void setbillno(int b)
//	{
//		billno = b;
//	}
//	int generatebillno()
//	{
//		bill b; int n = 0;
//		//fstream fin;
//		ifstream fin("bills.dat", ios::in | ios::binary );
//		while (fin.read((char*)&b, sizeof(b)))
//		{
//			n = b.getbillno();
//		}
//		fin.close();
//		if (n == 0)
//		{
//			n = 1;
//		}
//		else
//		{
//			n += 1;
//		}
//
//		b.setbillno(n);
//		ofstream fout("bills.dat", ios::out | ios::app | ios::binary);
//		fout.write((char*)&b, sizeof(b));
//		fout.close();
//		return n;
//	}
//};
//class billdetails :public catalog, public bill
//{
//protected:
//	int qty, amnt;
//public:
//	void setorder(int b, int i, char nm[], int p, int q)
//	{
//		catalog b;
//		billno = b;
//	prod_id = i;
//		strcpy_s(prod_name, nm);
//		prod_price = p;
//		prod_quan = q;
//		amnt = prod_price * prod_quan;
//
//	}
//
//	int getamount() { return amnt; }
//	void listbilldetails()
//	{
//		catalog s1;
//		cout.setf(ios::left);
//
//		cout << setw(5) <<s1. prod_id
//			<< setw(20) << s1.prod_name
//			<< setw(10) << s1.prod_price
//			<< setw(8) << s1.prod_quan
//			<< setw(12) << amnt
//			<< endl;
//	}
//	void getorder()
//	{
//		catalog x;
//
//		billdetails ord1;
//		int n, qt; int bn;
//		char prodname[20];
//		int ordertotal = 0;
//		bn = generatebillno();
//		ofstream fout("Orders.dat", ios::app);
//		do
//		{
//			system("cls");
//			cout << "0-End order and exit " << endl;
//			x.show_prod();
//			cout << "Item Id" << endl;
//
//			cin >> n;
//			if (n == 0)
//				goto out;
//
//			cout << "Order Id for: " << n << ":" << x.get_name_from_file(n) << "@Rs." << x.get_price_from_file(n) << endl;
//			cout << "Quantity " << endl;
//			cin >> qt;
//
//			ord1.setorder(bn, n, x.get_name_from_file(n), x.get_price_from_file(n), qt);
//
//
//fout.write((char*)&ord1, sizeof(ord1));
//			
//		} 
//		while (n != 0);
//		//fout.write((char*)&ord1, sizeof(ord1));
//
//
//	out:
//		fout.close();
//		cout << "End od order " << endl;
//		
//		
//		getorderdetails(bn);
//		//fout.close();
//		//system("cls");
//       // cout << "over and out" << endl;
//		//getorderdetails(bn);
//		//cout << "End pf order file" << endl;
//	   //headingfororderdetails();
//	   //getorderdetails(bn);
//	}
//	
//	void getorderdetails(int bn1)
//	{
//		billdetails ord;
//		int total = 0;
//		int no = 1;
//		fstream s;
//		int flag = 0;
//		s.open("Orders.dat",ios::in |  ios::binary | ios::out);
//		while (s.read((char*)&ord, sizeof(ord)))
//		{
//
////if (bn1 == getbillno())
////{
//				//cout.setf(ios::left);
//				//cout << setw(5) << no++;
//				ord.listbilldetails();
//				//total += ord.getamount();
//				//cout.setf(ios::left);
//			/*	break;
//			}*/
//
//		}
//		//s.close();
//	
//			cout.setf(ios::left);
//			cout << setw(40) << " "
//				<< setw(8) << "Total "
//
//				<< setw(12) << total << endl;
//			/*int ans = 0;
//			cout << "Press 1 to Go Back : ";
//			cin >> ans;
//			system("CLS");
//			ans = 1;
//			system("cls");*/
//			//s.close();
//
//
//
//
//	}
//};