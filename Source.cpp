#include<iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	while (1)
	{
		string pass;
		string passw = "password@123";
		system("cls");
		string msg = "HOTEL MANAGEMENT SYSTEM \n\n\n";
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
			string name, address, email,fbill="", phone;
			
			int room, hall, menu,total = 0;
			bool x = true;
			fbill = fbill + "sr.no Item                        price\n";
			cout << msg + "Full Name Of client: ";
			cin >> name;
			cout << "Phone Number of Client: ";
			cin >> phone;
			cout << "Email address Of Client: ";
			cin >> email;
			cout << "Address Of Client: ";
			cin >> address;
			cout << "select Type Of room:\n\n 1-suit \n 2-non-A.C\n 3-A.C\n 4-continue\n";
			cin >> room;
			switch (room)
			{
			case 1:
				total = total + 100;
				fbill = fbill + "1     suit                          100\n";
				break;
			case 2:
				total = total + 200;
				fbill = fbill + "1     non-A.C                       200\n";
				break;
			case 3:
				total = total + 300;
				fbill = fbill + "1     A.C                           300\n";
				break;
			case 4:
				fbill = fbill + "1     Non                           0\n";
				break;
			default:
				cout << "Error! operator is not correct";
				break;
			}
			cout << "select Type Of Function Hall:\n\n 1-Student \n 2-Regular\n 3-continue\n";
			cin >> hall;
			switch (hall)
			{
			case 1:
				total = total + 1000;
				fbill = fbill + "2     function hall student         1000\n";
				break;
			case 2:
				total = total + 2000;
				fbill = fbill + "2     function hall Regular         2000\n";
				break;
			case 3:
				fbill = fbill + "2     Non                           0\n";
				break;
			default:
				cout << "Error! option is not correct";
				break;
			}
			int cnt = 3;
			while (x == true)
			{
				std::string s = std::to_string(cnt);
				fbill = fbill + s;
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
				cnt++;
				string end;
				cout << "Do you want to continue (y/n): ";
				cin >> end;
				if (end == "n")
				{
					x = false;
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
				<< "            GST            18%" << endl
				<< "            Grand Total    "<<total+total*0.16<<endl
				<< "==============================\n"
				;

			system("\n pause");
		}
	}
}
