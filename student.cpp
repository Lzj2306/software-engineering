#include"student.h"
#include"check.h"
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void student::log()
{
	auth::log();
	login(username, passw);
}
void student::give_paper()
{
	cout << "Welcome Gave Your Paper " << endl;
	cout << "Select Subject : " << endl;
	for (int i = 0; i <= 4; i++)
	{
		cout << "Press " << i + 1 << " For " << subject[i] << endl;
	}
	int ch;
	cin >> ch;
	if (ch > 0 && ch < 7)
	{
		ifstream file;
		ofstream ans;
		file.open(file_of_papers[ch - 1]);
		ans.open(Ans_sheet[ch - 1], ios::app);
		int num;
		file >> num;
		string str;
		if (!file || !ans)
		{
			cout << "Something went wrong Try again...";
		}
		else
		{
			string q; string m;
			ans << endl;
			ans << num << " " << username;
			cin.ignore();
			int flag = 0;
			while (!file.eof())
			{
				if (flag == 0)
				{
					getline(file, q);
					flag = 1;
					continue;
				}
				getline(file, q);
				getline(file, m);
				cout << "Q : " << q << "\t\t\t Marks : " << m << endl;
				cout << "Ans : ";
				cin.getline(answer, 256);
				cout << answer << endl;
				ans << endl;
				ans << answer;
			}
			file.close();
		}
		int cho = 0;
		while (1)
		{
			cout << "Press 1 to back to student menu" << endl;
			cin >> cho;
			if (cho == 1)
				break;
		}
	}
}
void student::login(string user, string passw)
{
	int choice, ret = 0;
	username = user;
	if (check::check_student(username, passw) == 1)
	{
		while (1)
		{
		st_menu:
			do {
				system("cls");
				cout << "WELCOME " << user << endl;
				cout << "Press\n1. To View Date_sheet \n";
				cout << "2. To Give Paper \n";
				cout << "3. To  View Reults\n";
				cout << "4.Modify your information\n";
				cout << "5.Go to Discussion Forum\n";
				cout << "6. Go Back to Main Menu\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
					date_sheet::view_datesheet();
					char r;
					cout << "\nPress Any key to Go back :- "; cin >> r;
					goto st_menu;
					break;
				case 2:
					give_paper();
					break;
				case 3:
					result();
					break;
				case 4:
					modify();
					break;
				case 5:
					auth::talk();
					break;
				case 6:
					menu();
					break;
				default:
					cout << "INVALID CHOICE" << endl;
					cout << "press 1 to try again";
					cin >> ret;
					break;
				}
			} while (ret == 1);
		}
	}
	else
	{
		cout << "Roll No. Not found Ask Admin to register You Or try again.\nPress any Key to go back : ";
		char r;
		cin >> r;
		menu();
	}
}
void student::result()
{
	bool isf = 0;
	int choice;
	string sab, rs;
	int om;
	system("cls");
	cout << "Select Subject to View your result : " << endl;
	for (int i = 0; i <= 4; i++)
	{
		cout << "Press " << i + 1 << " to " << subject[i] << endl;
	}
	cin >> choice;
	choice = choice - 1;
	if (choice >= 0 && choice < 5)
	{
		ifstream res;
		res.open("result.txt");
		string str;
		getline(res, str);
		while (!res.eof())
		{
			res >> sab >> rs >> om;
			if (passw == rs && sab == subject[choice])
			{
				cout << "Your Total Marks are : " << om;
				isf = 1;
				char r;
				cout << endl;
				cout << "Press Any key to go back : ";
				cin >> r;
				return;
			}
		}
		if (!isf)
		{
			cout << "\nPaper is not check Yet. \n";
			char r;
			cout << "Press Any key to go back : ";
			cin >> r;
			return;
		}
	}
}
void student::modify()
{
	int ret = 0;
	do {
		system("cls");
		ifstream input;
		ofstream output;
		string tar;
		string cont, Name, Email, Class, ID;
		vector<vector<string>> temp;
		int index;
		cout << "Input the index to modify the user's information:\n1 for name\n2 for email\n3 for class\n";
		cout << "Your index:";
		cin >> index;
		cout << "Your new content:";
		cin >> cont;
		input.open("bin/student.txt");
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
		output.open("bin/student.txt", ios::out);
		output << "xxxx" << " " << "xxx" << " " << "xx" << " " << "x";
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i][3] == passw)
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
		cout << "Enter 1 to modify else back";
		cin >> ret;
	} while (ret == 1);
}