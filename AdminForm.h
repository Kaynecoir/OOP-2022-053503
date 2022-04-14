#pragma once
#include "ManagerForm.h"
#include "Administrator.h"

class AdminForm
{
public:
	Administrator* Ad;
	void Creat(int s)
	{
		cout << "Login: ";		cin >> Ad->Login;
		cout << "Password: ";	cin >> Ad->Password;
		cout << "Name: ";		cin >> Ad->Name;
		cout << "Surname: ";	cin >> Ad->SurName;
		cout << "Fathername: ";	cin >> Ad->FatherName;
		Ad->IndifNum = 3001 + s;
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
			if (v >= Ad->BORC->Size || v < 0)
				v = 0;
			system("cls");
			ClientForm ClF;
			Ad->BORC->Head();
			for (int i = 0; i < Ad->BORC->Size; i++)
			{
				ClF.cl = Ad->BORC->GetChose();
				cout << i + 1 << endl;
				if (v == i)
					ClF.Info();
				else
					cout << "\t" << ClF.cl->Name << " " << ClF.cl->SurName << endl;
				Ad->BORC->Next();
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
				Ad->BORC->Head();
				for (int i = 0; i < v; i++)
				{
					Ad->BORC->Next();
				}
				if (Ad->BORC->GetChose()->IndifNum != 0)
				{
					Client* temp = Ad->BORC->GetData();
					temp->IndifNum = 1001 + Ad->BOC->Size;
					Ad->BOC->Add(temp);
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
			if (v >= Ad->BOC->Size || v < 0)
				v = 0;
			system("cls");
			Ad->BOC->Head();
			for (int i = 0; i < Ad->BOC->Size; i++)
			{
				Client* cl = Ad->BOC->GetChose();
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
				Ad->BOC->Next();
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
				Ad->BOC->Head();
				for (int i = 0; i < v; i++)
				{
					Ad->BOC->Next();
				}
				Ad->ChoseClient = Ad->BOC->GetChose();
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
			if (v >= Ad->GlobMoneyBase->TransB.Size || v < 0)
				v = 0;
			system("cls");
			Ad->GlobMoneyBase->TransB.Head();
			for (int i = 0; i < Ad->GlobMoneyBase->TransB.Size; i++)
			{
				Transaction* tr = Ad->GlobMoneyBase->TransB.GetChose();
				if (v == i)
					cout << "->";
				cout << "\t" << tr->Giving->OwnerName << " > "
					<< tr->cash << " > "
					<< tr->Recipient->OwnerName << endl;
				cout << "\tStatus: " << ((tr->Activ) ? "Activ" : "Nonactiv") << endl;
				Ad->GlobMoneyBase->TransB.Next();
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
				Ad->GlobMoneyBase->TransB.Head();
				for (int i = 0; i < v; i++)
				{
					Ad->GlobMoneyBase->TransB.Next();
				}
				Transaction* t = Ad->GlobMoneyBase->TransB.GetChose();
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
				Ad->GlobMoneyBase->TransB.Head();
				for (int i = 0; i < v; i++)
				{
					Ad->GlobMoneyBase->TransB.Next();
				}
				Transaction* t = Ad->GlobMoneyBase->TransB.GetChose();
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