#include "Client.h"

Client::Client()
{

}
Client::Client(Client* cl)
{
	Name = cl->Name;
	SurName = cl->SurName;
	FatherName = cl->FatherName;
	Passport = cl->Passport;
	Telephone = cl->Telephone; 
	Email = cl->Telephone;
	Login = cl->Login;
	Password = cl->Password;
}

//void Client::MenuInvest()
//{
//	while (true)
//	{
//		system("cls");
//		cout << "\t1. Creat Investment\n";
//		cout << "\t2. TopUp Investment\n";
//		cout << "\t3. Withdrawal Investment\n";
//		cout << "\t4. Transacting Investment\n";
//		cout << "\t5. \n";
//		cout << "\t6. Exit\n";
//		int ch;
//		cout << "\nChose: ";
//		if ((cin >> ch).fail() || ch < 0)
//		{
//			system("cls");
//			cout << "Incorect enter variant. Enter variant again.\n\n";
//			cin.clear();
//		}
//		switch (ch)
//		{
//		case 1:
//			CreatInvestment();
//			break;
//		case 2:
//			TopUpInvest();
//			break;
//		case 3:
//			WithDrawalInvest();
//			break;
//		case 4:
//			Transacting();
//			break;
//		default:
//			return;
//			break;
//		}
//	}
//}
//void Client::CreatInvestment()
//{
//	Investment* t = GlobMoneyBase->CreateInvest(Name, SurName, IndifNum);
//
//	InvestB.Add(t);
//	cout << "Investment was creat\n";
//}
//void Client::TopUpInvest()
//{
//	if (ListInvest())
//		return;
//	double sum;
//	while (true)
//	{
//		cout << "Enter the sum what you want top up on Investment: ";
//		if ((cin >> sum).fail() || sum < 0)
//		{
//			system("cls");
//			cout << "\nIncorect enter sum. Enter sum again.\n\n";
//			cin.clear();
//		}
//		else
//			break;
//	}
//	if (ChoseInvest != NULL)
//		ChoseInvest->TopUp(sum);
//	ChoseInvest = NULL;
//	system("cls");
//}
//void Client::WithDrawalInvest()
//{
//	if (ListInvest())
//		return;
//	double sum;
//	while (true)
//	{
//		cout << "Enter the sum what you want withdrawal for Investment: ";
//		if ((cin >> sum).fail() || sum < 0)
//		{
//			system("cls");
//			cout << "\nIncorect enter sum. Enter sum again.\n\n";
//			cin.clear();
//		}
//		else
//			break;
//	}
//	if (ChoseInvest != NULL)
//		if (ChoseInvest->WithDrawal(sum))
//			cout << "Insufficient funds" << endl; _getch();
//	ChoseInvest = NULL;
//	system("cls");
//}
//bool Client::ListInvest()
//{
//	int v = 0;
//	while (true)
//	{
//		if (v >= InvestB.Size || v < 0)
//			v = 0;
//		system("cls");
//		InvestB.Head();
//		for (int i = 0; i < InvestB.Size; i++)
//		{
//			cout << i + 1 << endl;
//			if (v == i)
//			{
//				cout << "====================" << endl;
//				if (InvestB.GetChose()->status <= 1)
//				{
//					cout << "Owner: " << Name << " " << SurName << endl;
//					cout << "Indifination Number: " << InvestB.GetChose()->IndifNum << endl;
//					cout << "Cash: " << InvestB.GetChose()->cash << endl;
//					cout << "Status: ";
//					switch (InvestB.GetChose()->status)
//					{
//					case 0:
//						cout << "Open";
//						break;
//					case 1:
//						cout << "Frozen";
//						break;
//					}
//				}
//				else
//					cout << "Investment Close";
//				cout << endl << "====================" << endl;
//			}
//			else
//				cout << "\t" << InvestB.GetChose()->IndifNum << " : " << InvestB.GetChose()->status << endl;
//			InvestB.Next();
//		}
//		int ch;
//		cout << "\n1. Up\n2. Down\n3. Chose Investment\n4. Back\n";
//		cout << "\nChose: ";
//		if ((cin >> ch).fail() || ch < 0 || ch > 4)
//		{
//			system("cls");
//			cout << "\nIncorect enter variant. Enter variant again.\n\n";
//			cin.clear();
//		}
//		else if (ch == 1)
//			v--;
//		else if (ch == 2)
//			v++;
//		else if (ch == 3)
//		{
//			InvestB.Head();
//			for (int i = 0; i < v; i++)
//			{
//				InvestB.Next();
//			}
//			ChoseInvest = InvestB.GetChose();
//			return false;
//		}
//		else if (ch == 4)
//			return true;
//	}
//}
//void Client::Transacting()
//{
//	if (ListInvest())
//		return;
//	double sum;
//	while (true)
//	{
//		cout << "Enter the sum what you want withdrawal for Investment: ";
//		if ((cin >> sum).fail() || sum < 0)
//		{
//			system("cls");
//			cout << "\nIncorect enter sum. Enter sum again.\n\n";
//			cin.clear();
//		}
//		else
//			break;
//	}
//	int inv2;
//	while (true)
//	{
//		cout << "Enter the Indification Number of Investment what you want Transport yor cash: ";
//		if ((cin >> inv2).fail() || inv2 < 100001)
//		{
//			system("cls");
//			cout << "\nIncorect enter Indification Number. Enter Indification Number again.\n\n";
//			cin.clear();
//		}
//		else
//			break;
//	}
//	Investment* t = GlobMoneyBase->FindInvest(inv2);
//	if (t != NULL && ChoseInvest != NULL)
//		GlobMoneyBase->CreatTrans(ChoseInvest, t, sum);
//	ChoseInvest = NULL;
//	system("cls");
//}
//void Client::ChangeStatus()
//{
//	int ch;
//	ListInvest();
//	cout << "\t1. Open\n";
//	cout << "\t2. Frozen\n";
//	cout << "\t3. Close\n";
//	cout << "\t4. Back\n";
//	cout << "\nChose: ";
//	if ((cin >> ch).fail() || ch < 0)
//	{
//		system("cls");
//		cout << "Incorect enter variant. Enter variant again.\n\n";
//		cin.clear();
//	}
//	switch (ch)
//	{
//	case 1:
//		ChoseInvest->status = 0;
//		break;
//	case 2:
//		ChoseInvest->status = 1;
//		break;
//	case 3:
//		ChoseInvest->status = 2;
//		break;
//	default:
//		ChoseInvest = NULL;
//		return;
//	}
//}
void Client::TakeCredit()
{

}
//void Client::Creat(int s)
//{
//	cout << "Login: ";		cin >> Login;
//	cout << "Password: ";	cin >> Password;
//	cout << "Name: ";		cin >> Name;
//	cout << "Surname: ";	cin >> SurName;
//	cout << "Fathername: ";	cin >> FatherName;
//	cout << "Passport: ";	cin >> Passport;
//	cout << "Telephone: ";	cin >> Telephone;
//	cout << "Email: ";		cin >> Email;
//	IndifNum = s + 1;
//}
//void Client::Info()
//{
//	cout << "====================\n";
//	cout << "Name: \t\t"		<< Name << endl;
//	cout << "Surname: \t"		<< SurName << endl;
//	cout << "Fathername: \t"	<< FatherName << endl;
//	cout << "Passport: \t"		<< Passport << endl;
//	cout << "Telephone: \t"		<< Telephone << endl;
//	cout << "Email: \t\t"		<< Email << endl;
//	cout << "====================\n";
//}
//bool Client::Work()
//{
//	cout << "\t1. Work with Investment\n";
//	cout << "\t2. Work with Credit\n";
//	cout << "\t3. Exit\n";
//	int ch;
//	cout << "\nChose: ";
//	if ((cin >> ch).fail() || ch < 0)
//	{
//		system("cls");
//		cout << "Incorect enter variant. Enter variant again.\n\n";
//		cin.clear();
//	}
//	switch (ch)
//	{
//	case 1:
//		MenuInvest();
//		break;
//	case 2:
//		//MenuCredit();
//		break;
//	default:
//		return false;
//		break;
//	}
//	return true;
//}
void Client::Creat(int s) {}
bool Client::Work() { return true; }
Client::~Client()
{

}