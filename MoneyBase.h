#pragma once
#include "Investment.h" 
#include "Transaction.h"
//#include "Credit.h"
#include "DataBase.h"

class MoneyBase
{
public:
	DataBase<Investment> InvestB;	
	DataBase<Transaction> TransB;
	//DataBase<Credit> CreditB;

	Investment* CreateInvest(std::string on, std::string os, int oi)
	{
		Investment* temp = new Investment();
		temp->OwnerName = on;
		temp->OwnerSurname = os;
		temp->OwnerIndifNum = oi;
		temp->IndifNum = 100001 + InvestB.Size;
		InvestB.Add(temp);
		return temp;
	}
	Investment* FindInvest(int IndifNum)
	{
		InvestB.Head();
		Investment* in = NULL;
		for (int i = 0; i < InvestB.Size; i++)
		{
			if (InvestB.GetChose()->IndifNum == IndifNum)
			{
				in = InvestB.GetChose();
				break;
			}
			InvestB.Next();
		}
		return in;
	}
	void CreatTrans(Investment* in1, Investment* in2, double cash)
	{
		Transaction* temp = new Transaction(in1, in2, cash);
		TransB.Add(temp);
	}
};