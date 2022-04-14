#pragma once
//#include <string>
#include <iostream>
#include "DataBase.h"
#include "MoneyBase.h"
using namespace std;
class User
{
public:
	string Password, Login;
	int IndifNum;
	MoneyBase* GlobMoneyBase;

	User();
	User(string, string);
	virtual ~User();

	void SetMoneyBase(MoneyBase*);
	bool Enter(); 
	virtual bool Work();
	virtual void Creat(int);
};

