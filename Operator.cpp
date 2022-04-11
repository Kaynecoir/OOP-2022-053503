#include "Operator.h"

void Operator::Creat(int s)
{
	cout << "Login: ";		cin >> Login;
	cout << "Password: ";	cin >> Password;
	cout << "Name: ";		cin >> Name;
	cout << "Surname: ";	cin >> SurName;
	cout << "Fathername: ";	cin >> FatherName;
	cout << "Passport: ";	cin >> Passport;
	cout << "Telephone: ";	cin >> Telephone;
	cout << "Email: ";		cin >> Email;
	IndifNum = 2001 + s;
}
void Operator::SetListClient(DataBase<Client>* BOC)
{
	this->BOC = BOC;
}
bool Operator::Work()
{

	return false;
}
void Operator::ChangeStatus()
{

}
void Operator::History()
{

}