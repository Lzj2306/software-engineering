#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include"admin.h"
using namespace std;
void admin::log()
{
	auth::log();
	login(username, passw);
}
void admin::make_datesheet()
{
	int ret = 0;
	string Class;
	do {
		system("cls");
		cout << "\t\t\t----------Welcome admin----------- \n\n";
		cout << "\t\tMake Date sheet \n";
		cout << "Enter the class Name :";
		cin >> Class;
		ofstream date_sheet;
		date_sheet.open("bin/date_sheet.txt");
		if (!date_sheet)
		{
			cout << "File Not Found or permission denied.";
		}
		date_sheet << "exam";
		for (int i = 0; i < 5; i++)
		{
			cout << "For " << subject[i] << " : " << endl;
			cout << "Enter Date (DD-MM-YYYY) :\n";
			cout << "Enter Date : ";
			cin >> d;
			cout << "Enter Month: ";
			cin >> m;
			cout << "Enter Year: ";
			cin >> y;
			cout << "Enter Time";
			cout << "Enter Starting time : ";
			cin >> starting_time;
			cout << "Enter Ending Time : ";
			cin >> ending_time;
			date_sheet << "\n" << subject[i] << " " << d << " " << m << " " << y << " " << starting_time << " " << ending_time;
		}
		cout << "Enter 1 to make another datesheet else back";
		cin >> ret;
	} while (ret == 1);
}
void admin::add_student()
{
	int ret = 0;
	string student_name, student_email, student_class, student_rollNO;
	do {
		cout << "\t\tAdd Students \n";
		cout << "Enter Student Name: ";
		cin >> student_name;
		cout << "Enter student email: ";
		cin >> student_email;
		cout << "Enter student class: ";
		cin >> student_class;
		cout << "Enter student Roll No.: ";
		cin >> student_rollNO;
		ofstream Add_student;
		Add_student.open("bin/student.txt", ios::app);
		if (!Add_student)
		{
			cout << "File Not Found or permission denied.";
		}
		else
		{
			Add_student << "\n" << student_name << " " << student_email << " " << student_class << " " << student_rollNO;
		}
		Add_student.close();
		cout << "Enter 1 to add another student else back";
		cin >> ret;
	} while (ret == 1);
}
void admin::add_teacher()
{
	int ret = 0;
	string teacher_name, teacher_email, teach_Code;
	do {
		system("cls");
		cout << "Enter Teacher Name: ";
		cin >> teacher_name;
		cout << "Enter Teacher email: ";
		cin >> teacher_email;
		cout << "Enter Teacher Subect: ";
		for (int i = 0; i <= 5; i++)
		{
			cout << "Press " << i << " For " << subject[i] << endl;
		}
		int ch;
		cin >> ch;
		cout << "Enter Teacher Code : ";
		cin >> teach_Code;
		ofstream teacher;
		teacher.open("bin/teacher.txt", ios::app);
		if (!teacher)
		{
			cout << "File Not Found Something went wrong Try again.";
		}
		else
		{
			teacher << "\n" << teacher_name << " " << teacher_email << " " << subject[ch] << " " << teach_Code;
		}
		teacher.close();
		cout << "Enter 1 to add another student else back";
		cin >> ret;
	} while (ret == 1);
}
void admin::modify()
{
	int ret = 0;
	do {
		system("cls");
		int choice;
		cout << "Input 1 to modifye student or 2 to modify teacher" << endl;
		cout << "Your choice:";
		cin >> choice;
		ifstream input;
		ofstream output;
		string tar;
		string cont, Name, Email, Class, ID;
		vector<vector<string>> temp;
		int index;
		cout << "Input the user's ID:";
		cin >> tar;
		cout << "Input the index to modify the user's information:\n1 for name\n2 for email\n3 for class\n";
		cout << "Your index:";
		cin >> index;
		cout << "Your new content:";
		cin >> cont;
		if (choice == 1)
		{
			input.open("bin/student.txt");
		}
		else
			input.open("bin/teacher.txt");
		int flag = 0; string str;
		while (!input.eof())
		{
			if (flag == 0)
			{
				flag = 1;
				getline(input, str);
				continue;
			}
			vector<string> t;
			input >> Name >> Email >> Class >> ID;
			t.push_back(Name);
			t.push_back(Email);
			t.push_back(Class);
			t.push_back(ID);
			temp.push_back(t);
		}
		input.close();
		if (choice == 1)
		{
			output.open("bin/student.txt", ios::out);
		}
		else
			output.open("bin.teacher.txt", ios::out);
		output << "xxxx" << " " << "xxx" << " " << "xx" << " " << "x";
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i][3] == tar)
			{
				temp[i][index - 1] = cont;
				output << "\n" << temp[i][0] << " " << temp[i][1] << " " << temp[i][2] << " " << temp[i][3];
			}
			else
			{
				output << "\n" << temp[i][0] << " " << temp[i][1] << " " << temp[i][2] << " " << temp[i][3];
			}
		}
		output.close();
		cout << "Enter 1 to modify another user else back";
		cin >> ret;
	} while (ret == 1);
}
void admin::delete_user()
{
	int ret = 0;
	do {
		system("cls");
		int choice;
		cout << "Input 1 to delete student or 2 to delete teacher" << endl;
		cout << "Your choice:";
		cin >> choice;
		ifstream input;
		ofstream output;
		string tar;
		cout << "Input the user's ID:";
		cin >> tar;
		cout << endl;
		string Name, Email, Class, ID;
		vector<vector<string>> temp;
		if (choice == 1)
		{
			input.open("bin/student.txt");
		}
		else
		{
			input.open("bin/teacher.txt");
		}
		int flag = 0; string str;
		while (!input.eof())
		{
			if (flag == 0)
			{
				flag = 1;
				getline(input, str);
				continue;
			}
			vector<string> t;
			input >> Name >> Email >> Class >> ID;
			t.push_back(Name);
			t.push_back(Email);
			t.push_back(Class);
			t.push_back(ID);
			temp.push_back(t);
		}
		input.close();
		if (choice == 1)
		{
			output.open("bin/student.txt", ios::out);
		}
		else
			output.open("bin.teacher.txt", ios::out);
		output << "xxxx" << " " << "xxx" << " " << "xx" << " " << "x";
		for (int i = 0; i < temp.size(); ++i)
			if(temp[i][3]!=tar)
				output << "\n" << temp[i][0] << " " << temp[i][1] << " " << temp[i][2] << " " << temp[i][3];
		output.close();
		cout << "Enter 1 to delete another user else back";
		cin >> ret;
	} while (ret == 1);
}
void admin::show()
{
	int ret = 0;
	do {
		system("cls");
		ifstream look;
		string Name, email, Class, id;
		look.open("bin/student.txt");
		cout << "---------student---------" << endl;
		cout << "Name   Email     Class    ID" << endl;
		int flag = 0; string str;
		while (!look.eof())
		{
			if (flag == 0)
			{
				flag = 1;
				getline(look, str);
				continue;
			}
			look >> Name >> email >> Class >> id;
			cout << Name << "    " << email << "    " << Class << "    " << id << endl;
		}
		look.close();
		look.open("bin/teacher.txt");
		cout << "---------teacher---------" << endl;
		cout << "Name   Email     Class    ID" << endl;
		flag = 0;
		while (!look.eof())
		{
			if (flag == 0)
			{
				flag = 1;
				getline(look, str);
				continue;
			}
			look >> Name >> email >> Class >> id;
			cout << Name << "    " << email << "    " << Class << "    " << id << endl;
		}
		look.close();
		cout << "Enter any button to go back";
		cin >> ret;
	} while (0);
}
void admin::login(string user, string pass)
{
	int ret=0, choice;
	do {
		system("cls");
		if (user == admin_username && passw == admin_password)
		{
			cout << "Press\n1.For Add Student \n";
			cout << "2.For Add Teacher \n";
			cout << "3.To Make Date_Sheet \n";
			cout << "4.Print the users' information \n";
			cout << "5.Delete user\n";
			cout << "6.Modify user's information\n";
			cout << "7.Go to Discussion Forum\n";
			cout << "8.to Back to main menu\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				add_student();
				break;
			case 2:
				add_teacher();
				break;
			case 3:
				make_datesheet();
				break;
			case 4:
				show();
				break;
			case 5:
				delete_user();
				break;
			case 6:
				modify();
				break;
			case 7:
				auth::talk();
				break;
			case 8:
				menu();
			default:
				cout << "Invalid Choice Press 0 to Try Again else Exit..";
				cin >> ret;
				break;
			}
		}
		else
		{
			int cho;
			cout << "Name or Password is wrong!" << endl;
			cout << "Press 1.For enter again" << endl;
			cout << "      2.For exit" << endl;
			cout << "Your choice:";
			cin >> cho;
			if (cho == 1)
			{
				cout << endl;
				cout << "User Name:"; cin >> user;
				cout << "Password:"; cin >> pass;
			}
			if (cho == 2)
			{
				menu();
			}
		}
	} while (ret == 0);
}
