#include "Client.h"

Client::Client()
{
	IndifNum = 0;
	Login = "None";
	Password = "None";
}
Client::Client(string eLogin, string ePassword)
{
	IndifNum = 0;
	Login = eLogin;
	Password = ePassword;
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
void Client::CreatInvestment()
{
	cout << "";
}
void Client::SeeCapital()
{

}
void Client::WithDrawal()
{

}
void Client::Transacting()
{

}
void Client::ChangeStatus()
{

}
void Client::TakeCredit()
{

}
void Client::Creat(int s)
{
	cout << "Login: ";		cin >> Login;
	cout << "Password: ";	cin >> Password;
	cout << "Name: ";		cin >> Name;
	cout << "Surname: ";	cin >> SurName;
	cout << "Fathername: ";	cin >> FatherName;
	cout << "Passport: ";	cin >> Passport;
	cout << "Telephone: ";	cin >> Telephone;
	cout << "Email: ";		cin >> Email;
}
void Client::Info()
{
	cout << "====================\n";
	cout << "Name: \t\t"		<< Name << endl;
	cout << "Surname: \t"		<< SurName << endl;
	cout << "Fathername: \t"	<< FatherName << endl;
	cout << "Passport: \t"		<< Passport << endl;
	cout << "Telephone: \t"		<< Telephone << endl;
	cout << "Email: \t\t"		<< Email << endl;
	cout << "====================\n";
}
bool Client::Work()
{
	cout << "\t1. Creat Investment\n";
	cout << "\t2. See Capital\n";
	cout << "\t3. Withdrawal\n";
	cout << "\t4. Transacting\n";
	cout << "\t5. Change Status\n";
	cout << "\t6. Take Credit\n";
	cout << "\t7. Exit\n";
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
		SeeCapital();
		break;
	case 3:
		WithDrawal();
		break;
	case 4:
		Transacting();
		break;
	case 5:
		ChangeStatus();
		break;
	case 6:
		TakeCredit();
		break;
	default:
		return false;
		break;
	}
	return true;
}
Client::~Client()
{

}