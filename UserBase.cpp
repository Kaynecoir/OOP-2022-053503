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
	Client* temp = new Client();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	temp->Creat(0);
	//temp->GlobalMB = BOMoney;
	return temp;
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
	Operator* temp = new Operator();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	temp->Creat(s);
	temp->SetListClient(&BOC);
	BOO.Add(temp);
	return temp;
}
User* UserBase::RegManager(int s)
{
	Manager* temp = new Manager();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	temp->Creat(s);
	temp->SetListClient(&BOC);
	temp->SetListRegClient(&BORC);
	BOM.Add(temp);
	return temp;
}
User* UserBase::RegSpecialist(int s)
{
	Specialist* temp = new Specialist();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	temp->Creat(s);
	BOS.Add(temp);
	return temp;
}
User* UserBase::RegAdministrator(int s)
{
	Administrator* temp = new Administrator();
	cout << "Enter Personal Data in the appropriate fields\n\n";
	temp->Creat(s);
	temp->SetListClient(&BOC);
	temp->SetListRegClient(&BORC);
	BOA.Add(temp);
	return temp;
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
