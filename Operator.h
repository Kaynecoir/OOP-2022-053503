#pragma once
#include "Client.h"
class Operator : public User
{
public:
	string Name, SurName, FatherName;
	string Passport;
	string Telephone, Email;
	DataBase<Client>* BOC = NULL;
	virtual void SetListClient(DataBase<Client>*);
	virtual void ChangeStatus();
	virtual void History();
	virtual bool Work();
	virtual void Creat(int);
};

