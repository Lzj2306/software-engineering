#include"date_sheet.h"
#include<fstream>
#include<iostream>
using namespace std;
void date_sheet::view_datesheet()
{
	ifstream file;
	file.open("bin/date_sheet.txt");
	if (!file)
	{
		cout << "File Not Found ";
	}
	cout << "\n\t\t\t\t------DateSheet-----\n\n";
	int flag = 0; string str;
	while (!file.eof())
	{
		if (flag == 0)
		{
			flag = 1;
			getline(file, str);
			continue;
		}
		file >> s >> d >> m >> y >> starting_time >> ending_time;
		cout << "Subject : " << s << "\tDate : " << d << "-" << m << "-" << y << "\t\tStarting Time : " << starting_time << " \t\tEnding Time : " << ending_time << endl;
	}
	file.close();
}