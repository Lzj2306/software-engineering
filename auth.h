#pragma once
#ifndef AUTH_H
#define AUTH_H
#include<iostream>
using namespace std;
class auth {
protected:
	string username, passw;
public:
	virtual void log();
	void talk();
};
#endif