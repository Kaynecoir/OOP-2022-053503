#pragma once
#include "User.h"
//#include "MoneyBase.h"
class Client : public User
{
public:
	string Name, SurName, FatherName;
	string Passport;
	string Telephone, Email;
	//DataBase<Investment> IB;				// Investment Base of Person
	//MoneyBase* GlobalMB;					// MoneyBase of main process
	//DataBase<> CB;

	Client();
	Client(string, string);
	Client(Client*);
	virtual ~Client();

	void CreatInvestment();
	void SeeCapital();
	void WithDrawal();
	void Transacting();
	void ChangeStatus();
	void TakeCredit();
	bool Work();
	void Creat(int);
	void Info();
};

