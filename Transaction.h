#pragma once
#include "Investment.h"

class Transaction
{
public:
	double cash;
	Investment* Giving;
	Investment* Recipient;
	bool Activ = false;

	Transaction()
	{
		Giving = NULL;
		Recipient = NULL;
		cash = 0;
	}
	Transaction(Investment* in1, Investment* in2, double sum)
	{
		Giving = in1;
		Recipient = in2;
		cash = sum;
	}
};