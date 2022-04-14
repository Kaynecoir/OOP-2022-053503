#pragma once
#include <string>
#include <iostream>
#include <conio.h>

class Investment
{
public:
	std::string OwnerName, OwnerSurname;
	int OwnerIndifNum;
	double cash = 0;
	int status = 0;				// 0 - open, 1 - freez, 2 - block
	int IndifNum;				// 100 000 +

	Investment() {}
	bool TopUp(double cash)
	{
		if (status == 0)
		{
			this->cash += cash;
			return true;
		}
		return false;
	}
	bool WithDrawal(double cash)
	{
		if (status == 0 && this->cash - cash >= 0)
		{
			this->cash -= cash;
			return true;
		}
		return false;
	}

};