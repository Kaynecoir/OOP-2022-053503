#include "UserBase.h"

User* UserBase::Find(string l, string p)
{
	bool find = false;
	User* t;
	BOC.Head();				// Client
	for (int i = 0; i < BOC.Size; i++)
	{
		t = BOC.GetChose();
		if (t->Login == l && t->Password == p)
		{
			return t;
		}
		BOC.Next();
	}
	BOO.Head();			// Operator
	for (int i = 0; i < BOO.Size; i++)
	{
		t = BOO.GetChose();	
		if (t->Login == l && t->Password == p)
		{
			return t;
		}
		BOO.Next();
	}
	BOM.Head();				// Manager
	for (int i = 0; i < BOM.Size; i++)
	{
		t = BOM.GetChose();
		if (t->Login == l && t->Password == p)
		{
			return t;
		}
		BOM.Next();
	}
	BOS.Head();			// Specialist
	for (int i = 0; i < BOS.Size; i++)
	{
		t = BOS.GetChose();	
		if (t->Login == l && t->Password == p)
		{
			return t;
		}
		BOS.Next();
	}
	BOA.Head();			// Administrator
	for (int i = 0; i < BOA.Size; i++)
	{
		t = BOA.GetChose();		
		if (t->Login == l && t->Password == p)
		{
			return t;
		}
		BOA.Next();
	}
	return new User();				// if no find
}

Client* UserBase::RegClient()
{
	//Client* temp = new Client;
	ClientForm ClF;
	ClF.cl = new Client();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	ClF.Creat(0);
	ClF.cl->SetMoneyBase(BOMoney);
	return ClF.cl;
}
void UserBase::AddRegClient()
{
	BORC.Add(RegClient());
}
void UserBase::AddClient(Client* c, int s)
{
	c->IndifNum = 1001 + s;
	BOC.Add(c);
	BORC.Head();
	while (c != BORC.GetChose())
		BORC.Next();
	BORC.DeleteChose();
}
User* UserBase::RegOperator(int s)
{
	OperatorForm OpF;
	OpF.op = new Operator();
	//Operator* temp = new Operator();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	OpF.Creat(s);
	OpF.op->SetListClient(&BOC);
	OpF.op->SetMoneyBase(BOMoney);
	BOO.Add(OpF.op);
	return OpF.op;
}
User* UserBase::RegManager(int s)
{
	ManagerForm ManF;
	ManF.man = new Manager();
	//Manager* temp = new Manager();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	ManF.Creat(s);
	ManF.man->SetListClient(&BOC);
	ManF.man->SetListRegClient(&BORC);
	ManF.man->SetMoneyBase(BOMoney);
	BOM.Add(ManF.man);
	return ManF.man;
}
User* UserBase::RegSpecialist(int s)
{
	Specialist* temp = new Specialist();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	temp->Creat(s);
	BOS.Add(temp);
	temp->SetMoneyBase(BOMoney);
	return temp;
}
User* UserBase::RegAdministrator(int s)
{
	//Administrator* temp = new Administrator();
	AdminForm AdF;
	AdF.Ad = new Administrator();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	AdF.Creat(s);
	AdF.Ad->SetListClient(&BOC);
	AdF.Ad->SetListRegClient(&BORC);
	AdF.Ad->SetMoneyBase(BOMoney);
	BOA.Add(AdF.Ad);
	return AdF.Ad;
}
void UserBase::ListUser()
{
	cout << "\nClient " << BOC.Size << endl;
	BOC.Head();
	for (int i = 0; i < BOC.Size; i++)
	{
		cout << "Login: " << BOC.GetChose()->Login << "\tPassword: " << BOC.GetChose()->Password << endl;
		BOC.Next();
	}
	cout << "\nOperator " << BOO.Size << endl;
	BOO.Head();
	for (int i = 0; i < BOO.Size; i++)
	{
		cout << "Login: " << BOO.GetChose()->Login << "\tPassword: " << BOO.GetChose()->Password << endl;
		BOO.Next();
	}
	cout << "\nManager " << BOM.Size << endl;
	BOM.Head();
	for (int i = 0; i < BOM.Size; i++)
	{
		cout << "Login: " << BOM.GetChose()->Login << "\tPassword: " << BOM.GetChose()->Password << endl;
		BOM.Next();
	}
	cout << "\nAdministrator " << BOA.Size << endl;
	BOA.Head();
	for (int i = 0; i < BOA.Size; i++)
	{
		cout << "Login: " << BOA.GetChose()->Login << "\tPassword: " << BOA.GetChose()->Password << endl;
		BOA.Next();
	}
}
User* UserBase::Creat()
{
	return NULL;
}
