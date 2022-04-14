#pragma once
#include "Operator.h"
class Manager : public Operator
{
public:
	DataBase<Client>* BOU = NULL;
	DataBase<Client>* BORC = NULL;
	virtual void SetListRegClient(DataBase<Client>*);
	//virtual void Confirm();
	virtual bool Work();
	virtual void Creat(int);
};

