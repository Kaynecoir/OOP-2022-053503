#pragma once
#include "Operator.h"

class OperatorForm
{
public:
	Operator* op;
	void Creat(int s)
	{
		cout << "Login: ";		cin >> op->Login;
		cout << "Password: ";	cin >> op->Password;
		cout << "Name: ";		cin >> op->Name;
		cout << "Surname: ";	cin >> op->SurName;
		cout << "Fathername: ";	cin >> op->FatherName;
		op->IndifNum = 2001 + s;
	}
	void SeeListClient()
	{
		int v = 0;
		while (true)
		{
			if (v >= op->BOC->Size || v < 0)
				v = 0;
			system("cls");
			op->BOC->Head();
			for (int i = 0; i < op->BOC->Size; i++)
			{
				Client* cl = op->BOC->GetChose();
				cout << i + 1 << endl;
				if (v == i)
				{
					cout << "====================" << endl;
					cout << "Name: " << cl->Name << endl;
					cout << "Surname: " << cl->SurName << endl;
					cout << "Fathername: " << cl->FatherName << endl;
					cout << "Passport: " << cl->Passport << endl;
					cout << "Telephone: " << cl->Telephone << endl;
					cout << "Email: " << cl->Email << endl;
					cout << "====================" << endl;
				}
				else
					cout << "\t" << cl->Name << " : " << cl->SurName << endl;
				op->BOC->Next();
			}
			int ch;
			cout << "\n1. Up\n2. Down\n3. Chose Client\n4. Back\n";
			cout << "\nChose: ";
			if ((cin >> ch).fail() || ch < 0 || ch > 4)
			{
				system("cls");
				cout << "\nIncorect enter variant. Enter variant again.\n\n";
				cin.clear();
			}
			else if (ch == 1)
				v--;
			else if (ch == 2)
				v++;
			else if (ch == 3)
			{
				op->BOC->Head();
				for (int i = 0; i < v; i++)
				{
					op->BOC->Next();
				}
				op->ChoseClient = op->BOC->GetChose();
				return;
			}
			else if (ch == 4)
				return;
		}
	}
	bool Work()
	{
		cout << "\t1. See All History Transaction\n";
		cout << "\t2. Change Investment status\n";
		cout << "\t3. Exit\n";
		int ch;
		cout << "\nChose: ";
		if ((cin >> ch).fail() || ch < 0)
		{
			system("cls");
			cout << "Incorect enter variant. Enter variant again.\n\n";
			cin.clear();
		}
		switch (ch)
		{
		case 1:
			AllHistory();
			break;
		case 2:
			//SeeListClient();
			break;
		default:
			return false;
			break;
		}
		return true;
	}
	void ChangeStatus()
	{

	}
	void AllHistory()
	{
		int v = 0;
		while (true)
		{
			if (v >= op->GlobMoneyBase->TransB.Size || v < 0)
				v = 0;
			system("cls");
			op->GlobMoneyBase->TransB.Head();
			for (int i = 0; i < op->GlobMoneyBase->TransB.Size; i++)
			{
				Transaction* tr = op->GlobMoneyBase->TransB.GetChose();
				if (v == i)
					cout << "->";
				cout << "\t" << tr->Giving->OwnerName << " > "
					<< tr->cash << " > "
					<< tr->Recipient->OwnerName << endl;
				cout << "\tStatus: " << ((tr->Activ) ? "Activ" : "Nonactiv") << endl;
				op->GlobMoneyBase->TransB.Next();
			}
			int ch;
			cout << "\n1. Up\n2. Down\n3. Activate Transaction\n4. Deactivate Transaction\n5. Back\n";
			cout << "\nChose: ";
			if ((cin >> ch).fail() || ch < 0 || ch > 4)
			{
				system("cls");
				cout << "\nIncorect enter variant. Enter variant again.\n\n";
				cin.clear();
			}
			else if (ch == 1)
				v--;
			else if (ch == 2)
				v++;
			else if (ch == 3)
			{
				op->GlobMoneyBase->TransB.Head();
				for (int i = 0; i < v; i++)
				{
					op->GlobMoneyBase->TransB.Next();
				}
				Transaction* t = op->GlobMoneyBase->TransB.GetChose();
				if (!(t->Activ) && t->Giving->WithDrawal(t->cash))
				{
					t->Recipient->TopUp(t->cash);
					t->Activ = true;
				}
				else
					cout << "Insufficient funds" << endl;
				_getch();
				return;
			}
			else if (ch == 4)
			{
				op->GlobMoneyBase->TransB.Head();
				for (int i = 0; i < v; i++)
				{
					op->GlobMoneyBase->TransB.Next();
				}
				Transaction* t = op->GlobMoneyBase->TransB.GetChose();
				if ((t->Activ) && t->Recipient->WithDrawal(t->cash))
				{
					t->Giving->TopUp(t->cash);
					t->Activ = false;
				}
				else
					cout << "Insufficient funds" << endl;
				_getch();
			}
			else
				return;
		}
	}
};