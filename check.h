#pragma once
#ifndef CHECK_H
#define CHECK_H
#include<iostream>
using namespace std;
class check {
public:
	bool check_class(string abc);
	bool check_student(string roll, string pass);
	bool check_teacher(string roll, string pass,string&sub);
	string check_subject(string code);
};
#endif