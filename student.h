#pragma once
#ifndef STU_H
#define STH_H
#include"paper.h"
#include"auth.h"
#include"check.h"
#include"date_sheet.h"
#include<iostream>
#include"constant.h"
#include"menu.h"
#include"first.h"
using namespace std;
class student :public auth, public check, public date_sheet, public paper,public first
{
public:
	char answer[256];
	void log();
	void give_paper();
	void login(string user, string passw);
	void result();
	void modify();
};
#endif