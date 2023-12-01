#include"check.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool check::check_class(string abc)
{
	fstream file;
	file.open("bin/student.txt", ios::in);
	if (!file)
	{
		cout << "Something went wrong Try again...";
	}
	string student_name, student_email, student_class, student_rollNO;
	bool isfound = 0;
	int flag = 0; string n;
	while (!file.eof())
	{
		if (flag == 0)
		{
			flag = 1;
			getline(file, n);
			continue;
		}
		file >> student_name >> student_email >> student_class >> student_rollNO;
		if (abc == student_class) {
			isfound = 1;
			break;
		}
	}
	return isfound;
}
bool check::check_student(string roll, string pass)
{
	fstream file;
	file.open("bin/student.txt", ios::in);
	if (!file)
	{
		cout << "Something went wrong Try again...";
	}
	string student_name, student_email, student_class, student_rollNO;
	bool isfound = 0;
	int flag = 0; string c;
	while (!file.eof())
	{
		if (flag == 0)
		{
			flag = 1;
			getline(file, c);
			continue;
		}
		file >> student_name >> student_email >> student_class >> student_rollNO;
		if (roll == student_name && pass == student_rollNO)
		{
			isfound = 1;
			break;
		}
	}
	return isfound;
}
bool check::check_teacher(string roll, string pass,string& sub)
{
	fstream file;
	file.open("bin/teacher.txt", ios::in);
	if (!file)
	{
		cout << "Something went wrong Try again...";
	}
	string student_name, student_email, student_class, student_rollNO;
	bool isfound = 0;
	int flag = 0; string c;
	while (!file.eof())
	{
		if (flag == 0)
		{
			flag = 1;
			getline(file, c);
			continue;
		}
		file >> student_name >> student_email >> student_class >> student_rollNO;
		if (pass == student_rollNO && roll == student_name)
		{
			sub = student_class;
			isfound = 1;
			break;
		}
	}
	return isfound;
}
string check::check_subject(string code)
{
	string sub;
	fstream file;
	file.open("bin/teacher.txt", ios::in);
	if (!file)
	{
		cout << "Something went wrong Try again...";
	}
	string student_name, student_email, student_class, student_rollNO;
	int flag = 0; string c;
	while (!file.eof())
	{
		if (flag == 0)
		{
			flag = 1;
			getline(file, c);
			continue;
		}
		file >> student_name >> student_email >> student_class >> student_rollNO;
		if (code == student_rollNO)
		{
			sub = student_class;
			break;
		}
	}
	return sub;
}