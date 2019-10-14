#include<iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
string name, address, email, fbill = "", phone, passw = "password@123", msg = "HOTEL MANAGEMENT SYSTEM \n\n\n", pass;
int room, hall, menu, total = 0, mainmenu, cnt = 1;
bool x = true;

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
	cout << "select Type Of room:\n\n 1-suit \n 2-non-A.C\n 3-A.C\n 4-Mainmenu\n";
	cin >> room;
	switch (room)
	{
	case 1:
		total = total + 100;
		fbill = fbill + "     suit                          100\n";
		break;
	case 2:
		total = total + 200;
		fbill = fbill + "     non-A.C                       200\n";
		break;
	case 3:
		total = total + 300;
		fbill = fbill + "     A.C                           300\n";
		break;
	case 4:
		fbill = fbill + "     Non                           0\n";
		break;
	default:
		cout << "Error! operator is not correct";
		break;
	}
}
void functionhall()
{
	cout << "select Type Of Function Hall:\n\n 1-Student \n 2-Regular\n 3-Mainmenu\n";
	cin >> hall;
	switch (hall)
	{
	case 1:
		total = total + 1000;
		fbill = fbill + "     function hall student         1000\n";
		break;
	case 2:
		total = total + 2000;
		fbill = fbill + "     function hall Regular         2000\n";
		break;
	case 3:
		fbill = fbill + "     Non                           0\n";
		break;
	default:
		cout << "Error! option is not correct";
		break;
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
int main()
{
	while (1)
	{
		system("cls");
		cout << msg + "Enter password$: ";
		cin >> pass;
		if (pass != passw)
		{
			system("cls");

			cout << msg + "!!!You Have Enter Wrong Password$\n\n";
			system("pause");
		}
		while (pass == passw)
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
			if (big == 1)
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
						<< "3.RESTURENT"<<endl
						<< "ENTER OPTION : ";					
					cin >> mainmenu;
					switch (mainmenu)
					{
					case 1:
						fbill = fbill + to_string(cnt);
						cnt++;
						checkinn();
						break;
					case 2:
						fbill = fbill + to_string(cnt);
						cnt++;
						functionhall();
						break;
					case 3:
						fbill = fbill + to_string(cnt);
						cnt++;
						resturent();
						break;
					default:
						cout << "Error! operator is not correct";
						break;
					}
					string end;
					cout << "Do you want to continue (y/n): ";
					cin >> end;
					if (end == "y")
					{
						y = false;
					}
				}
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
					<< "==============================\n"
					;
				std::fstream fs;
				fs.open("record.txt", std::fstream::in | std::fstream::out | std::fstream::app);
				fs
					<< "Name of Client           :" << name << endl
					<< "Phone number of client   :" << phone << endl
					<< "Email address of client  :" << email << endl
					<< "Address of client        :" << address << endl
					<< fbill
					<< " TOTAL  " << total << endl
					<< "Grand Total including gst  " << total + total * 0.16 << endl
					<< "==============================\n"
					;
				fs.close();
				fbill = "";
				total = 0;
				system("\n pause");
			}
		}
	}
}
