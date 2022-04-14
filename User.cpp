#include "User.h"

User::User()
{
	IndifNum = 0;
	Login = "None";
	Password = "None";
}
User::User(string eLogin, string ePassword)
{
	IndifNum = 0;
	Login = eLogin;
	Password = ePassword;
}
User::~User()
{

}

void User::SetMoneyBase(MoneyBase* MB)
{
	GlobMoneyBase = MB;
}
bool User::Enter()
{
	return false;
}
bool User::Work()
{
	return false;
}
void User::Creat(int s)
{

}