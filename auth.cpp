#include"auth.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
void auth::log()
{
	cout << "Enter Username  : "; cin >> username;
	cout << "Enter Password : "; cin >> passw;
}
void auth::talk()
{
	system("cls");
	ifstream input("talk.txt");
	vector<string> chat;
	int flag = 0; string str;
	while (!input.eof())
	{
		if (flag == 0)
		{
			flag = 1;
			getline(input, str);
			continue;
		}
		getline(input, str);
		cout << str << endl;
	}
	input.close();
	int a;
	cout << "Input 1 to wirte sentence or 2 to return:";
	cin >> a;
	cout << endl;
	while (a == 1)
	{
		ofstream output;
		output.open("talk.txt", ios::app);
		string words;
		cout << "Write your sentence then enter to send:";
		cin.ignore();
		getline(cin, words);
		cout << endl;
		string tar = username + ":" + words;
		output << "\n" << tar;
		output.close();
		cout << "Input 1 to continue talk or 2 to return:";
		cin >> a;
	}
	return;
}