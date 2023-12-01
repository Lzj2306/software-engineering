#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include"menu.h"
#include"constant.h"
#include"teacher.h"
#include"student.h"
#include"admin.h"
#include"auth.h"
using namespace std;

void menu()
{
	first* obj;
	int ret=0;
mnu:
	do {
		int choice;
		system("cls");
		cout << "==========\t\t\t\tEXAM PORTAL\t\t\t\t=========\nPress\n";
		cout << "1. For Admin" << endl;
		cout << "2. For Student" << endl;
		cout << "3. For Teacher" << endl;
		cout << "4. To Exit" << endl;
		cout << "Select : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			obj = new admin;
			obj->log();
			break;
		case 2:
			obj = new student;
			obj->log();
			break;
		case 3:
			obj = new teacher;
			obj->log();
			break;
		case 4:
			cout << "\n\tThanks for Using//\n";
			exit(1);
		default:
			cout << "Invalid Choice Press 0 to Try Again else Exit..";
			cin >> ret;
			break;
		}
	} while (ret == 0);
}
int main()
{
	menu();
}