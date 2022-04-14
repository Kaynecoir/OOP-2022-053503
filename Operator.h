#pragma once
#include "ClientForm.h"
class Operator : public User
{
public:
	string Name, SurName, FatherName;
	DataBase<Client>* BOC = NULL;
	Client* ChoseClient = NULL;
	Transaction* ChoseTransaction = NULL;
	virtual void SetListClient(DataBase<Client>*);
	virtual void SeeListClient();
	virtual void ChangeStatus();
	virtual void AllHistory();
	virtual bool Work();
	virtual void Creat(int);
};

