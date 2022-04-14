#pragma once
#include "Client.h"

class ClientForm
{
public:
	Client* cl = NULL;
	void MenuInvest()
	{
		while (true)
		{
			system("cls");
			cout << "\t1. Creat Investment\n";
			cout << "\t2. TopUp Investment\n";
			cout << "\t3. Withdrawal Investment\n";
			cout << "\t4. Transacting Investment\n";
			cout << "\t5. \n";
			cout << "\t6. Exit\n";
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
				CreatInvestment();
				break;
			case 2:
				TopUpInvest();
				break;
			case 3:
				WithDrawalInvest();
				break;
			case 4:
				Transacting();
				break;
			default:
				return;
				break;
			}
		}
	}
	bool ListInvest()
	{
		int v = 0;
		while (true)
		{
			if (v >= cl->InvestB.Size || v < 0)
				v = 0;
			system("cls");
			cl->InvestB.Head();
			for (int i = 0; i < cl->InvestB.Size; i++)
			{
				cout << i + 1 << endl;
				if (v == i)
				{
					cout << "====================" << endl;
					if (cl->InvestB.GetChose()->status <= 1)
					{
						cout << "Owner: " << cl->Name << " " << cl->SurName << endl;
						cout << "Indifination Number: " << cl->InvestB.GetChose()->IndifNum << endl;
						cout << "Cash: " << cl->InvestB.GetChose()->cash << endl;
						cout << "Status: ";
						switch (cl->InvestB.GetChose()->status)
						{
						case 0:
							cout << "Open";
							break;
						case 1:
							cout << "Frozen";
							break;
						}
					}
					else
						cout << "Investment Close";
					cout << endl << "====================" << endl;
				}
				else
					cout << "\t" << cl->InvestB.GetChose()->IndifNum << " : " << cl->InvestB.GetChose()->status << endl;
				cl->InvestB.Next();
			}
			int ch;
			cout << "\n1. Up\n2. Down\n3. Chose Investment\n4. Back\n";
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
				cl->InvestB.Head();
				for (int i = 0; i < v; i++)
				{
					cl->InvestB.Next();
				}
				cl->ChoseInvest = cl->InvestB.GetChose();
				return false;
			}
			else if (ch == 4)
				return true;
		}
	}
	void Transacting()
	{
		if (ListInvest())
			return;
		double sum;
		while (true)
		{
			cout << "Enter the sum what you want withdrawal for Investment: ";
			if ((cin >> sum).fail() || sum < 0)
			{
				system("cls");
				cout << "\nIncorect enter sum. Enter sum again.\n\n";
				cin.clear();
			}
			else
				break;
		}
		int inv2;
		while (true)
		{
			cout << "Enter the Indification Number of Investment what you want Transport yor cash: ";
			if ((cin >> inv2).fail() || inv2 < 100001)
			{
				system("cls");
				cout << "\nIncorect enter Indification Number. Enter Indification Number again.\n\n";
				cin.clear();
			}
			else
				break;
		}
		Investment* t = cl->GlobMoneyBase->FindInvest(inv2);
		if (t != NULL && cl->ChoseInvest != NULL)
			cl->GlobMoneyBase->CreatTrans(cl->ChoseInvest, t, sum);
		cl->ChoseInvest = NULL;
		system("cls");
	}
	void ChangeStatus()
	{
		int ch;
		ListInvest();
		cout << "\t1. Open\n";
		cout << "\t2. Frozen\n";
		cout << "\t3. Close\n";
		cout << "\t4. Back\n";
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
			cl->ChoseInvest->status = 0;
			break;
		case 2:
			cl->ChoseInvest->status = 1;
			break;
		case 3:
			cl->ChoseInvest->status = 2;
			break;
		default:
			cl->ChoseInvest = NULL;
			return;
		}
	}
	void Creat(int s)
	{
		cout << "Login: ";		cin >> cl->Login;
		cout << "Password: ";	cin >> cl->Password;
		cout << "Name: ";		cin >> cl->Name;
		cout << "Surname: ";	cin >> cl->SurName;
		cout << "Fathername: ";	cin >> cl->FatherName;
		cout << "Passport: ";	cin >> cl->Passport;
		cout << "Telephone: ";	cin >> cl->Telephone;
		cout << "Email: ";		cin >> cl->Email;
		cl->IndifNum = s + 1;
	}
	void Info()
	{
		cout << "====================\n";
		cout << "Name: \t\t" << cl->Name << endl;
		cout << "Surname: \t" << cl->SurName << endl;
		cout << "Fathername: \t" << cl->FatherName << endl;
		cout << "Passport: \t" << cl->Passport << endl;
		cout << "Telephone: \t" << cl->Telephone << endl;
		cout << "Email: \t\t" << cl->Email << endl;
		cout << "====================\n";
	}
	bool Work()
	{
		cout << "\t1. Work with Investment\n";
		cout << "\t2. Work with Credit\n";
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
			MenuInvest();
			break;
		case 2:
			//MenuCredit();
			break;
		default:
			return false;
			break;
		}
		return true;
	}
	void CreatInvestment()
	{
		Investment* t = cl->GlobMoneyBase->CreateInvest(cl->Name, cl->SurName, cl->IndifNum);

		cl->InvestB.Add(t);
		cout << "Investment was creat\n";
	}
	void TopUpInvest()
	{
		if (ListInvest())
			return;
		double sum;
		while (true)
		{
			cout << "Enter the sum what you want top up on Investment: ";
			if ((cin >> sum).fail() || sum < 0)
			{
				system("cls");
				cout << "\nIncorect enter sum. Enter sum again.\n\n";
				cin.clear();
			}
			else
				break;
		}
		if (cl->ChoseInvest != NULL)
			cl->ChoseInvest->TopUp(sum);
		cl->ChoseInvest = NULL;
		system("cls");
	}
	void WithDrawalInvest()
	{
		if (ListInvest())
			return;
		double sum;
		while (true)
		{
			cout << "Enter the sum what you want withdrawal for Investment: ";
			if ((cin >> sum).fail() || sum < 0)
			{
				system("cls");
				cout << "\nIncorect enter sum. Enter sum again.\n\n";
				cin.clear();
			}
			else
				break;
		}
		if (cl->ChoseInvest != NULL)
			if (!cl->ChoseInvest->WithDrawal(sum))
				cout << "Insufficient funds" << endl; _getch();
		cl->ChoseInvest = NULL;
		system("cls");
	}
};