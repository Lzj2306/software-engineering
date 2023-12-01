#pragma once
#ifndef PAPER_H
#define PAPER_H
class paper
{
private:
	int ret = 0;
	int total_marks = 0;
	int total_qes;
	char question[555];
	int time_allowed;
	char ans[999];
public:
	void make_paper();
};
#endif