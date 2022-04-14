#include "Manager.h"

void Manager::SetListRegClient(DataBase<Client>* BORC)
{
	this->BORC = BORC;
}
//void Manager::Creat(int s)
//{
//	cout << "Login: ";		cin >> Login;
//	cout << "Password: ";	cin >> Password;
//	cout << "Name: ";		cin >> Name;
//	cout << "Surname: ";	cin >> SurName;
//	cout << "Fathername: ";	cin >> FatherName;
//	IndifNum = 3001 + s;
//}
//bool Manager::Work()
//{
//	cout << "\t1. Confirm Client Registration\n";
//	cout << "\t2. \n";
//	cout << "\t3. \n";
//	cout << "\t4. Exit\n";
//	int ch;
//	cout << "\nChose: ";
//	if ((cin >> ch).fail() || ch < 0)
//	{
//		system("cls");
//		cout << "\nIncorect enter variant. Enter variant again.\n\n";
//		cin.clear();
//	}
//	switch (ch)
//	{
//	case 1:
//		Confirm();
//		break;
//	case 2:
//		break;
//	case 3:
//		break;
//	case 4:
//		return false;
//		break;
//	default:
//		break;
//	}
//	return true;
//}
//void Manager::Confirm()
//{
//	int v = 0;
//	while (true)
//	{
//		if (v >= BORC->Size || v < 0)
//			v = 0;
//		system("cls");
//		ClientForm ClF;
//		BORC->Head();
//		for (int i = 0; i < BORC->Size; i++)
//		{
//			ClF.cl = BORC->GetChose();
//			cout << i + 1 << endl;
//			if (v == i)
//				ClF.Info();
//			else
//				cout << "\t" << ClF.cl->Name << " " << ClF.cl->SurName << endl;
//			BORC->Next();
//		}
//		int ch;
//		cout << "\n1. Up\n2. Down\n3. Confirm Rgistration\n4. Back\n";
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
//			BORC->Head();
//			for (int i = 0; i < v; i++)
//			{
//				BORC->Next();
//			}
//			if (BORC->GetChose()->IndifNum != 0)
//			{
//				Client* temp = BORC->GetData();
//				temp->IndifNum = 1001 + BOC->Size;
//				BOC->Add(temp);
//			}
//		}
//		else if (ch == 4)
//			return;
//	}
//}
bool Manager::Work() { return true; }
void Manager::Creat(int s) {}