#include"paper.h"
#include<iostream>
#include"constant.h"
#include<fstream>
using namespace std;
void paper::make_paper()
{
	int each_marks;
	do {
		cout << "Make Paper \n";
		cout << "Select Subject : " << endl;
		for (int i = 0; i <= 4; i++)
		{
			cout << "Press " << i + 1 << " For " << subject[i] << endl;
		}
		cout << "==> ";
		int ch;
		cin >> ch;
		if (ch > 0 && ch < 7)
		{
			cout << "Enter total number of Questions : ";
			cin >> total_qes;
			cout << "Total Time Allowed(in minutes) : ";
			cin >> time_allowed;
			cout << "Enter Question : \n";
			ofstream paper;
			paper.open(file_of_papers[ch - 1]);
			if (!paper)
			{
				cout << "Something went wrong Try again...";
			}
			paper << total_qes << " question";
			for (int i = 0; i < total_qes; i++)
			{
				cout << "Q" << i + 1 << " : ";
				cin.ignore();
				cin.getline(question, 256);
				cout << "Enter marks for this Question : "; cin >> each_marks;
				paper << endl;
				paper << question;
				paper << endl;
				paper << each_marks;
				total_marks = total_marks + each_marks;
			}
			cout << "Total marks : " << total_marks << endl;
			paper.close();
		}
		else
		{
			cout << "class Not found";
		}
		cout << "Enter 1 to make another datesheet else back";
		cin >> ret;
	} while (ret);
}