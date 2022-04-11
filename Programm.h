#pragma once
#include <iostream>
#include <stdlib.h>
//#include "Bank.h"
#include "UserBase.h"
//#include "MoneyBase.h"
class Programm
{
public:
	UserBase BOU;				// Base Of User
	//MoneyBase BOMoney;			// Base Of Money
	User* MainUser = NULL;				// User what work in programm
	//DataBase<Bank> BOB;			// Base of Bank
	//Programm();
	virtual ~Programm();
	void ListUser();
	bool Start();				// Chose Enter or Register
	bool Registration();		// Registration User
	bool Enter();				// Enter in User

								// bool funct() - return true if we are come back on function upper and continue work
								// and          - return false if we want exit

	void MainProcess();

};

