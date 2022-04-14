#include "Operator.h"

void Operator::Creat(int s)
{
	cout << "Login: ";		cin >> Login;
	cout << "Password: ";	cin >> Password;
	cout << "Name: ";		cin >> Name;
	cout << "Surname: ";	cin >> SurName;
	cout << "Fathername: ";	cin >> FatherName;
	IndifNum = 2001 + s;
}
void Operator::SetListClient(DataBase<Client>* BOC)
{
	this->BOC = BOC;
}
void Operator::SeeListClient()
{
	int v = 0;
	while (true)
	{
		if (v >= BOC->Size || v < 0)
			v = 0;
		system("cls");
		BOC->Head();
		for (int i = 0; i < BOC->Size; i++)
		{
			cout << i + 1 << endl;
			if (v == i)
			{
				cout << "====================" << endl;
				cout << "Name: " << BOC->GetChose()->Name << endl;
				cout << "Surname: " << BOC->GetChose()->SurName << endl;
				cout << "Fathername: " << BOC->GetChose()->FatherName << endl;
				cout << "Passport: " << BOC->GetChose()->Passport << endl;
				cout << "Telephone: " << BOC->GetChose()->Telephone << endl;
				cout << "Email: " << BOC->GetChose()->Email << endl;
				cout << "====================" << endl;
			}
			else
				cout << "\t" << BOC->GetChose()->Name << " : " << BOC->GetChose()->SurName << endl;
			BOC->Next();
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
			BOC->Head();
			for (int i = 0; i < v; i++)
			{
				BOC->Next();
			}
			ChoseClient = BOC->GetChose();
			return;
		}
		else if (ch == 4)
			return;
	}
}
bool Operator::Work()
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
		
		break;
	default:
		return false;
		break;
	}
	return true;
}
void Operator::ChangeStatus()
{

}
void Operator::AllHistory()
{
	int v = 0;
	while (true)
	{
		if (v >= GlobMoneyBase->TransB.Size || v < 0)
			v = 0;
		system("cls");
		GlobMoneyBase->TransB.Head();
		for (int i = 0; i < GlobMoneyBase->TransB.Size; i++)
		{
			if (v == i)
				cout << "->";
			cout << "\t" << GlobMoneyBase->TransB.GetChose()->Giving->OwnerName << " > "
				<< GlobMoneyBase->TransB.GetChose()->cash << " > "
				<< GlobMoneyBase->TransB.GetChose()->Recipient->OwnerName << endl;
			cout << "\tStatus: " << ((GlobMoneyBase->TransB.GetChose()->Activ) ? "Activ" : "Nonactiv") << endl;
			GlobMoneyBase->TransB.Next();
		}
		int ch;
		cout << "\n1. Up\n2. Down\n3. Activate Transaction\n4. Back\n";
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
			GlobMoneyBase->TransB.Head();
			for (int i = 0; i < v; i++)
			{
				GlobMoneyBase->TransB.Next();
			}
			Transaction* t = GlobMoneyBase->TransB.GetChose();
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
			return;
	}
}