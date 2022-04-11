#pragma once
#include <string>
#include <iostream>
#include "DataBase.h"
using namespace std;
class User
{
public:
	string Password, Login;
	int IndifNum;

	User();
	User(string, string);
	virtual ~User();

	bool Enter(); 
	virtual bool Work();
	virtual void Creat(int);
};

