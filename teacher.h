#pragma once
#ifndef TEA_H
#define TEA_H
#include"auth.h"
#include"check.h"
#include"paper.h"
#include"date_sheet.h"
#include"menu.h"
#include"constant.h"
#include"first.h"
class teacher :public auth, public check, public paper, public date_sheet,public first
{
public:
	string sub;
	void log();
	void login(string user, string passw);
	void check_paper();
	void show();
	void change_grades();
	void check_exam();
};
#endif