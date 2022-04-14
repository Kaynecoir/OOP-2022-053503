#pragma once
#include "User.h"

class Client : public User
{
public:
	string Name, SurName, FatherName;
	string Passport;
	string Telephone, Email;
	DataBase<Investment> InvestB;				// Investment Base of Person
	//DataBase<Credit> CreditB;
	Investment* ChoseInvest;
	//Credit* ChoseCredit;

	Client();
	Client(Client*);
	virtual ~Client();

	//	Invest funct
	void MenuInvest();
	void CreatInvestment();
	void TopUpInvest();
	void WithDrawalInvest();
	bool ListInvest();
	void Transacting();
	void WithDrawal();

	//	Credit funct
	//void MenuCredit();
	void ListCredit();
	void ChangeStatus();
	void TakeCredit();

	//	Other funct
	bool Work();
	void Creat(int);
	void Info();
};

