#include<iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include<stdlib.h>
using namespace std;
string name, address, email, fbill = "", passw = "password@123", msg = "HOTEL MANAGEMENT SYSTEM \n\n\n ", pass, paymentmethod;
int room, hall, pay, menu, total = 0, mainmenu, adr1, adr2; string phone;
bool x = true;
class avail
{
public:
	int suit, NAC, AC;
}a;
void read()
{
	system("cls");
	cout << msg;
	std::ifstream f("record.txt");

	if (f.is_open())
		std::cout << f.rdbuf();

	system("pause");
}
void checkinn()
{
	fstream f;
	f.open("avail.txt", ios::out | ios::in | ios::binary);
	f.read((char*)&a, sizeof(a));
	cout << "select Type Of room:\n\n 1-suit " << a.suit << " available \n 2-non-A.C " << a.NAC << " available \n 3-A.C " << a.AC << " available\n";
	cin >> room;
	switch (room)
	{
	case 1:if (a.suit < 1)
	{
		cout << "Sorry room not available"; _getch(); checkinn();
	}
		  total = total + 100;
		  fbill = fbill + "     suit                          100\n";
		  a.suit = a.suit - 1; cout << "ROOM BOOKED SUCCESSFULLY\n";
		  adr1 = f.tellg();
		  adr2 = sizeof(int);
		  f.seekp(adr1 - adr2);
		  f.write((char*)&a.suit, sizeof(a.suit));
		  break;
	case 2:
		if (a.NAC < 1)
		{
			cout << "Sorry room not available"; _getch(); checkinn();
		}
		total = total + 200;
		fbill = fbill + "     non-A.C                       200\n";
		a.NAC = a.NAC - 1; cout << "ROOM BOOKED SUCCESSFULLY\n";
		adr1 = f.tellg();
		adr2 = sizeof(int);
		f.seekp(adr1 - 2 * adr2);
		f.write((char*)&a.NAC, sizeof(a.NAC));
		break;
	case 3:
		if (a.AC < 1)
		{
			cout << "Sorry room not available"; _getch(); checkinn();
		}
		total = total + 300;
		fbill = fbill + "     A.C                           300\n";
		a.AC = a.AC - 1; cout << "ROOM BOOKED SUCCESSFULLY\n";
		adr1 = f.tellg();
		adr2 = sizeof(int);
		f.seekp(adr1 - 3 * adr2);
		f.write((char*)&a.AC, sizeof(a.AC));
		break;
	default:
		cout << "Error! operator is not correct";
		_getch(); checkinn();
	}
	f.close();
}
void functionhall()
{
	cout << "select Type Of Function Hall:\n\n 1-Student \n 2-Regular\n";
	cin >> hall;
	switch (hall)
	{
	case 1:
		total = total + 1000;
		fbill = fbill + "     function hall student         1000\n"; cout << "FUNCTION HALL BOOKED\n";
		break;
	case 2:
		total = total + 2000;
		fbill = fbill + "     function hall Regular         2000\n"; cout << "FUNCTION HALL BOOKED\n";
		break;
	default:
		cout << "Error! option is not correct";
		_getch(); functionhall();
	}
}
void resturent()
{

	cout << "Restaurant:\n\n =============Menu=============" << endl
		<< "1. Press '1' to Buy Pizza" << endl
		<< "2. Press '2' to Buy Rice" << endl
		<< "3. Press '3' to Buy Spaghetti" << endl
		<< "4. Press '4' to Buy Tea" << endl
		<< "5. Press '5' to Buy Garlic bread" << endl
		<< endl << "Please select Items from the menu: ";
	cin >> menu;
	switch (menu)
	{
	case 1:
		total = total + 100;
		fbill = fbill + "     Pizza                         100\n";
		break;
	case 2:
		total = total + 60;
		fbill = fbill + "     Rice                          60\n";
		break;
	case 3:
		total = total + 80;
		fbill = fbill + "     Spaghetti                     80\n";
		break;
	case 4:
		total = total + 25;
		fbill = fbill + "     Tea                           25\n";
		break;
	case 5:
		total = total + 70;
		fbill = fbill + "     Garlic bread                  70\n";
		break;
	default:
		cout << "Error! operator is not correct";
		break;

	}
}
void payment()
{
	cout << msg + "select Type Of Payment Method:\n\n 1-Paytm \n 2-Card Payment\n 3-UPI\n 4-CASH payment\n";
	cin >> pay;
	switch (pay)
	{
	case 1:
		paymentmethod = "PAID USING PAYTM!!\n"; cout << "PAID USING PAYTM!!\n";
		break;
	case 2:
		paymentmethod = "PAID USING CARD!!\n"; cout << "PAID USING CARD!!\n";
		break;
	case 3:
		paymentmethod = "PAID USING UPI!!\n"; cout << "PAID USING UPI!!\n";
		break;
	case 4:
		paymentmethod = "PAID USING CASH!!\n"; cout << "PAID USING CASH!!\n";
		break;
	default:
		cout << "Error! option is not correct";
		_getch(); payment();
	}
}
int main()
{
	fstream f;
	f.open("avail.txt", ios::out | ios::in | ios::binary);
	a.suit = 10; a.NAC = 10; a.AC = 10; f.write((char*)&a, sizeof(a)); f.close();
	while (1)
	{
		system("cls");
		cout << msg + "Enter password$: "; int i = 0; char z;

		char ch;
		ch = _getch();
		while (ch != 13) {

			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}		if (pass != passw)
		{
			system("cls");

			cout << msg + "!!!You Have Enter Wrong Password$\n\n";
			pass = "";
			system("pause");
		}
		while (pass == passw)
		{
			while (1)
			{

				system("cls");
				int big;
				cout << msg + "1.NEWCLIENT" << endl
					<< "2.CHECK RECORD" << endl

					<< "ENTER OPTION : ";
				cin >> big;
				if (big == 2)
				{
					read();
				}
				else if (big == 1)
				{
					system("cls");

					fbill = fbill + "sr.no Item                        price\n";
					cout << msg + "Full Name Of client: ";
					cin >> name;
					cout << "Phone Number of Client: ";
					cin >> phone;
					cout << "Email address Of Client: ";
					cin >> email;
					cout << "Address Of Client: ";
					cin >> address;
					system("cls");
					bool y = true;
					while (y == true)
					{
						cout << msg + "1.CHECKINN" << endl
							<< "2.FUNCTION HALL" << endl
							<< "3.RESTURENT" << endl
							<< "ENTER OPTION : ";
						cin >> mainmenu;
						switch (mainmenu)
						{
						case 1:

							checkinn();
							break;
						case 2:

							functionhall();
							break;
						case 3:

							resturent();
							break;
						default:
							cout << "Error! operator is not correct";
							break;
						}
						string end;
						cout << "Do you want to book anything else (y/n)?: ";
						cin >> end;
						if (end == "y")
						{
							y = true;
						}
						else if (end == "n")
						{
							y = false;
						}
						else
						{
							cout << "Invalid"; exit(0);
						}

					}
					system("cls");
					payment();
					system("pause");
					system("cls");
					cout << msg + "==========final bill==========\n\n"
						<< "=========Client Detail========\n\n"
						<< "Name of Client           :" << name << endl
						<< "Phone number of client   :" << phone << endl
						<< "Email address of client  :" << email << endl
						<< "Address of client        :" << address << endl
						<< "==============================\n\n"
						<< fbill
						<< "==============================\n"
						<< "            TOTAL          " << total << endl
						<< "            GST            16%" << endl
						<< "            Grand Total    " << total + total * 0.16 << endl
						<< "==============================\n" + paymentmethod
						;
					fstream fs;
					fs.open("record.txt", std::fstream::in | std::fstream::out | std::fstream::app);
					fs
						<< "Name of Client           :" << name << endl
						<< "Phone number of client   :" << phone << endl
						<< "Email address of client  :" << email << endl
						<< "Address of client        :" << address << endl
						<< fbill
						<< " TOTAL  " << total << endl
						<< "Grand Total including gst  " << total + total * 0.16 << endl
						<< "==============================\n" + paymentmethod
						;
					fs.close();
					fbill = "";
					total = 0;
					system("\n pause");
				}
				else
				{
					cout << "Invalid"; _getch();
				}
			}
		}
	}
}
