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

bool User::Enter()
{
	return false;
}
bool User::Work()
{
	cout << "Enter ";
	return false;
}
void User::Creat(int s)
{
	cout << "Creat ";
}