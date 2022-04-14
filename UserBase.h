#pragma once
#include "Client.h"
#include "Specialist.h"
#include "Administrator.h"
#include "DataBase.h"
#include "ClientForm.h"

class UserBase
{
public:
	DataBase<Client> BOC;			// Base of Client
	DataBase<Client> BORC;			// Base of Registration Client
	DataBase<Operator> BOO;			// Base of Operator
	DataBase<Manager> BOM;			// Base of Manager
	DataBase<Specialist> BOS;		// Base of Specialist
	DataBase<Administrator> BOA;	// Base of Administrator
	MoneyBase* BOMoney;

	UserBase() {};
	virtual ~UserBase() {};


	User* Find(string, string);
	User* Creat();
	Client* RegClient();				// Creat data about Client
	void AddRegClient();
	void AddClient(Client*, int);			// Add Client in Base of Client
	User* RegOperator(int);
	User* RegManager(int);
	User* RegSpecialist(int);
	User* RegAdministrator(int);
	void ListUser();
};

