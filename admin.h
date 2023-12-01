#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include"check.h"
#include"auth.h"
#include"date_sheet.h"
#include<string>
#include<iostream>
#include"constant.h"
#include"menu.h"
#include"first.h"
using namespace std;
class admin :public check, public auth, public date_sheet,public first
{
private:
	const string admin_username = "admin";
	const string admin_password = "123";
public:
	void delete_user();
	void modify();
	void show();
	void log();
	void make_datesheet();
	void add_student();
	void add_teacher();
	void login(string user, string pass);
};
#endif