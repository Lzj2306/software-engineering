#pragma once
#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
using namespace std;
class date_sheet
{
protected:
	string s;
	int d, m, y;
	int starting_time, ending_time;
public:
	void view_datesheet();
};
#endif