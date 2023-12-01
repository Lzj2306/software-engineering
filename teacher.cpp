#include"teacher.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
void teacher::log()
{
	auth::log();
	login(username, passw);
}
void teacher::login(string user, string passw)
{
	int choice;
	if (check::check_teacher(username, passw,sub))
	{
		while (1)
		{
		teach_menu:
			system("cls");
			cout << "WELCOME TEACHERS....." << endl;
			cout << "Press\n1.To Make paper \n";
			cout << "2.To Check paper \n";
			cout << "3.To  View DateSheet\n";
			cout << "4.Print students' information\n";
			cout << "5.Go to Discussion Forum\n";
			cout << "6.Change student's grades\n";
			cout << "7.Check out the basics of the exam\n";
			cout << "8.To back to main Menu\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				paper::make_paper();
				break;
			case 2:
				system("cls");
				check_paper();
				break;
			case 3:
				system("cls");
				date_sheet::view_datesheet();
				char r;
				cout << "\nPress Any key to Go back :- "; cin >> r;
				goto teach_menu;
				break;
			case 4:
				show();
				break;
			case 5:
				auth::talk();
				break;
			case 6:
				change_grades();
				break;
			case 7:
				check_exam();
				break;
			case 8:
				menu();
			default:
				cout << "INVALID CHOICE";
				break;
			}
		}
	}
	else
	{
		menu();
		cout << "Emp No. Not found Ask Admin to register You Or try again.\nThanks...";
	}
}
void teacher::check_paper()
{
	string n, e, s, check_roll;
	int r, obtained_marks;
	ifstream ans_sht, file, ques;
	ofstream res;
	string a, b;
	string temp_subject;
	file.open("bin/student.txt");
	res.open("result.txt", ios::app);
	if (!file)
	{
		cout << "Something went wrong Try again...";
	}
	string p = check::check_subject(passw);
	cout << "Check Paper of " << p << endl;
	cout << "Select Student To Check his/her Paper : " << endl;
	int flag = 1; string str;
	while (!file.eof())
	{
		if (flag == 1)
		{
			flag = 0;
			getline(file, str);
			continue;
		}
		file >> n >> e >> s >> r;
		cout << "Name : " << n << ";  Roll Number : " << r << endl;
	}
	cout << "\nEnter Name and Roll Number to Check : " << endl;
	string name;
	cout << "Name:";
	cin >> name;
	cout << endl;
	cout << "Roll Number:";
	cin >> check_roll;
	cout << endl;
	if (check::check_student(name, check_roll))
	{
		for (int i = 0; i <= 5; i++)
		{
			if (p == subject[i])
			{
				temp_subject = subject[i];
				ans_sht.open(Ans_sheet[i]);
				if (!ans_sht)
				{
					cout << "You haven't had your test yet." << endl;
					cout << "Press any button to back to your menu:";
					int cho;
					cin >> cho;
					return;
				}
				else
				{
					string str;
					getline(ans_sht, str);
					int num; string nm;
					while (1)
					{
						ans_sht >> num;
						ans_sht >> nm;
						if (nm != name)
						{
							for (int i = 0; i <= num; ++i)
								getline(ans_sht, str);
						}
						else
							break;
					}
					getline(ans_sht, str);
					for (int i = 0; i < num; ++i)
					{
						getline(ans_sht, str);
						cout << "Answer of question " << i + 1 << ":" << str << endl;
					}
					cout << "Enter The Total marks for this student : ";
					cin >> obtained_marks;
					res << "\n" << temp_subject << " " << check_roll << " " << obtained_marks;
					cout << "Press any button to return to tearcher menu:";
					int cho;
					cin >> cho;
				}
			}
		}
	}
	else
	{
		cout << "please enter correct roll no. Press 1 to go back";
		char r;
		menu();
	}
}
void teacher::show()
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
		cout << "Enter any button to go back";
		cin >> ret;
	} while (0);
}
void teacher::change_grades()
{
	int ret = 0;
	do {
		system("cls");
		ifstream look;
		string Subject, ID, grades;
		look.open("result.txt");
		vector<vector<string>> temp;
		int flag = 0; string str;
		while (!look.eof())
		{
			if (flag == 0)
			{
				flag = 1;
				getline(look, str);
				continue;
			}
			vector<string> t;
			look >> Subject >> ID >> grades;
			if (Subject == sub)
			{
				t.push_back(Subject);
				t.push_back(ID);
				t.push_back(grades);
				temp.push_back(t);
			}
		}
		look.close();
		string tar;
		cout << "Input the student's ID:";
		cin >> tar;
		ofstream output;
		output.open("result.txt", ios::out);
		output << "xxx" << " " << "xx" << " " << "x";
		int sign = 0;
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i][1] == tar)
			{
				cout << "Here is the student's grades of the subject you taught:\n";
				cout << temp[i][1] << " " << temp[i][2];
				string new_grades;
				cout << endl;
				cout << "Input new grades:";
				cin >> new_grades;
				temp[i][2] = new_grades;
				sign = 1;
			}
			output << "\n" << temp[i][0] << " " << temp[i][1] << " " << temp[i][2];
		}
		if (sign == 0)
			cout << "The student didn't study the subject you taught\n";
		cout << "Input 1 to change again or other to return";
		cin >> ret;
	} while (ret==1);
}
void teacher::check_exam()
{
	int ret = 0;
	do {
		system("cls");
		ifstream look;
		string Subject, ID, grades;
		look.open("result.txt");
		vector<vector<string>> temp;
		int flag = 0; string str;
		while (!look.eof())
		{
			if (flag == 0)
			{
				flag = 1;
				getline(look, str);
				continue;
			}
			vector<string> t;
			look >> Subject >> ID >> grades;
			if (Subject == sub)
			{
				t.push_back(Subject);
				t.push_back(ID);
				t.push_back(grades);
				temp.push_back(t);
			}
		}
		look.close();
		int first_g = 0, second_gear = 0, third_gear = 0, fourth_gear = 0, fifth_gear = 0;
		int biggest = 0, lowest = 100;
		for (int i = 0; i < temp.size(); ++i)
		{
			int g = stoi(temp[i][2]);
			if (g <= 100 && g > 90)
				++first_g;
			else if (g <= 90 && g > 80)
				++second_gear;
			else if (g <= 80 && g > 70)
				++third_gear;
			else if (g <= 70 && g > 60)
				++fourth_gear;
			else
				++fifth_gear;
			biggest = max(biggest, g);
			lowest = min(lowest, g);
		}
		cout << "Here is the Basics of results:\n";
		cout << "100~90:" << first_g << "人" << endl;
		cout << "90~80:" << second_gear << "人" << endl;
		cout << "80~70:" << third_gear << "人" << endl;
		cout << "70~60:" << fourth_gear << "人" << endl;
		cout << "<=60:" << fifth_gear << "人" << endl;
		cout << "The higgest score is:" << biggest << endl;
		cout << "The lowest score is:" << lowest << endl;
		vector<int> gr;
		double sum = 0;
		for (int i = 0; i < temp.size(); ++i)
		{
			gr.push_back(stoi(temp[i][2]));
			sum += stoi(temp[i][2]);
		}
		sort(gr.begin(), gr.end());
		cout << "The median is:" << gr[gr.size() / 2] << endl;
		cout << "The average is:" << sum / gr.size() << endl;
		cout << "Input any button to return";
		cin >> ret;
	} while (0);
}