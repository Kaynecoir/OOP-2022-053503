#pragma once
#include "OperatorForm.h"
#include "Manager.h"

class ManagerForm
{
public:
	Manager* man;
	void Creat(int s)
	{
		cout << "Login: ";		cin >> man->Login;
		cout << "Password: ";	cin >> man->Password;
		cout << "Name: ";		cin >> man->Name;
		cout << "Surname: ";	cin >> man->SurName;
		cout << "Fathername: ";	cin >> man->FatherName;
		man->IndifNum = 3001 + s;
	}
	bool Work()
	{
		cout << "\t1. Confirm Client Registration\n";
		cout << "\t2. \n";
		cout << "\t3. \n";
		cout << "\t4. Exit\n";
		int ch;
		cout << "\nChose: ";
		if ((cin >> ch).fail() || ch < 0)
		{
			system("cls");
			cout << "\nIncorect enter variant. Enter variant again.\n\n";
			cin.clear();
		}
		switch (ch)
		{
		case 1:
			Confirm();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return false;
			break;
		default:
			break;
		}
		return true;
	}
	void Confirm()
	{
		int v = 0;
		while (true)
		{
			if (v >= man->BORC->Size || v < 0)
				v = 0;
			system("cls");
			ClientForm ClF;
			man->BORC->Head();
			for (int i = 0; i < man->BORC->Size; i++)
			{
				ClF.cl = man->BORC->GetChose();
				cout << i + 1 << endl;
				if (v == i)
					ClF.Info();
				else
					cout << "\t" << ClF.cl->Name << " " << ClF.cl->SurName << endl;
				man->BORC->Next();
			}
			int ch;
			cout << "\n1. Up\n2. Down\n3. Confirm Rgistration\n4. Back\n";
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
				man->BORC->Head();
				for (int i = 0; i < v; i++)
				{
					man->BORC->Next();
				}
				if (man->BORC->GetChose()->IndifNum != 0)
				{
					Client* temp = man->BORC->GetData();
					temp->IndifNum = 1001 + man->BOC->Size;
					man->BOC->Add(temp);
				}
			}
			else if (ch == 4)
				return;
		}
	}
	void SeeListClient()
	{
		int v = 0;
		while (true)
		{
			if (v >= man->BOC->Size || v < 0)
				v = 0;
			system("cls");
			man->BOC->Head();
			for (int i = 0; i < man->BOC->Size; i++)
			{
				Client* cl = man->BOC->GetChose();
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
				man->BOC->Next();
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
				man->BOC->Head();
				for (int i = 0; i < v; i++)
				{
					man->BOC->Next();
				}
				man->ChoseClient = man->BOC->GetChose();
				return;
			}
			else if (ch == 4)
				return;
		}
	}
	void ChangeStatus()
	{

	}
	void AllHistory() // История всех
	{
		int v = 0;
		while (true)
		{
			if (v >= man->GlobMoneyBase->TransB.Size || v < 0)
				v = 0;
			system("cls");
			man->GlobMoneyBase->TransB.Head();
			for (int i = 0; i < man->GlobMoneyBase->TransB.Size; i++)
			{
				Transaction* tr = man->GlobMoneyBase->TransB.GetChose();
				if (v == i)
					cout << "->";
				cout << "\t" << tr->Giving->OwnerName << " > "
					<< tr->cash << " > "
					<< tr->Recipient->OwnerName << endl;
				cout << "\tStatus: " << ((tr->Activ) ? "Activ" : "Nonactiv") << endl;
				man->GlobMoneyBase->TransB.Next();
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
				man->GlobMoneyBase->TransB.Head();
				for (int i = 0; i < v; i++)
				{
					man->GlobMoneyBase->TransB.Next();
				}
				Transaction* t = man->GlobMoneyBase->TransB.GetChose();
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
				man->GlobMoneyBase->TransB.Head();
				for (int i = 0; i < v; i++)
				{
					man->GlobMoneyBase->TransB.Next();
				}
				Transaction* t = man->GlobMoneyBase->TransB.GetChose();
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