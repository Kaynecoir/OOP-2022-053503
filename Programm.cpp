#include "Programm.h"
#include <conio.h>

void Programm::MainProcess()
{
	BOU.BOMoney = &GlobalMB;
	bool EndProcess = false;
	while (!EndProcess)
	{
		system("cls");
		EndProcess = Start();
	}
}
bool Programm::Start()
{
	int ch = 3;
	while (true)
	{
		cout << "\t1.Enter\n";
		cout << "\t2.Registration\n";
		cout << "\t3.Exit\n";

		cout << "\nChose: ";
		if ((cin >> ch).fail() || ch <= 0)
		{
			system("cls");
			cout << "Incorect enter variant. Enter variant again.\n\n";
			cin.clear();
		}
		else break;
	}
	switch (ch)
	{
	case 1:
		Enter();
		break;
	case 2:
		Registration();
		break;
	case 3:
		return true;
		break;
	case 5:
		ListUser();
		break;
	default:
		return true;
		break;
	}
	return false;
}
bool Programm::Registration()
{
	string l, p;
	int ch;
	while (true)
	{
		cout << "Register as who?" << endl;
		cout << "\t1. Client\n";
		cout << "\t2. Operator\n";
		cout << "\t3. Manager\n";
		cout << "\t4. Specialist\n";
		cout << "\t5. Administrator\n";
		cout << "\t6. Back\n";

		cout << "\nChose: ";
		if ((cin >> ch).fail() || ch < 0)
		{
			system("cls");
			cout << "Incorect enter variant. Enter variant again.\n\n";
			cin.clear();
		}
		else break;
	}
	switch (ch)
	{
	case 1:
		BOU.AddRegClient();
		break;
	case 2:
		BOU.RegOperator(BOU.BOO.Size);
		break;
	case 3:
		BOU.RegManager(BOU.BOM.Size);
		break;
	case 4:
		BOU.RegSpecialist(BOU.BOS.Size);
		break;
	case 5:
		BOU.RegAdministrator(BOU.BOA.Size);
		break;
	default:
		return false;
		break;
	}
	return true;
}
bool Programm::Enter()
{
	string l, p;
	while (true)
	{
		cout << "Login: ";		cin >> l;
		cout << "Password: ";	cin >> p;
		User* temp = BOU.Find(l, p);
		if (temp->IndifNum == 0)
		{
			delete temp;
			cout << "\nIncorect Login/Password\n";
			int ch;
			cout << "1. Retry Entry data\n";
			cout << "2. Back in Menu\n";
			cout << "\nChose: ";
			if ((cin >> ch).fail() || ch < 0)
			{
				system("cls");
				cout << "\nIncorect enter variant. Enter variant again.\n\n";
				cin.clear();
			}
			else if(ch != 1)
			{
				break;
			}
			system("cls");
		}
		else
		{
			MainUser = temp;
			break;
		}
	}
	if (MainUser == NULL)
	{
		_getch();
		return true;
	}
	if (MainUser->IndifNum < 2000)
	{
		ClientForm ClF;
		ClF.cl = (Client*)MainUser;
		do
		{
			system("cls");
		} while (ClF.Work());
	}
	else
	{
		do
		{
			system("cls");
		} while (MainUser->Work());
	}
	MainUser = NULL;
	return false;
}
void Programm::ListUser()
{
	BOU.ListUser();
	_getch();
}
Programm::~Programm()
{

}
