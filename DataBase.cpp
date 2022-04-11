#include "DataBase.h"

//T DataBase<T>::Find(string f) // Будут раписаны для каждого класса отдельно
//template <typename T>
//void DataBase<T>::DeleteChose()
//{
//	Note<T>* p = chose->prev;
//	Note<T>* n = chose->next;
//	delete chose->data;
//	delete chose;
//	p->next = n;
//	n->prev = p;
//	chose = head;
//	chose->activ = true;
//	Size--;
//}
//template <typename T>
//void DataBase<T>::Delete()
//{
//	Note<T>* p = tail->prev;
//	delete tail->data;
//	delete tail;
//	p->next = NULL;
//	tail = p;
//	Size--;
//}
//template <typename T>
//void DataBase<T>::DeleteAll()
//{
//	while (head != NULL)
//	{
//		Note<T>* temp = head->next;
//		delete head;
//		head = temp;
//	}
//}
//template <typename T>
//void DataBase<T>::Next()
//{
//	chose->activ = false;
//	if (chose->next != NULL)
//		chose = chose->next;
//	else
//		chose = head;
//	chose->activ = true;
//}
//template <typename T>
//void DataBase<T>::Prev()
//{
//	chose->activ = false;
//	if (chose->prev != NULL)
//		chose = chose->prev;
//	else
//		chose = tail;
//	chose->activ = true;
//}
//template <typename T>
//void DataBase<T>::Head()
//{
//	chose->activ = false;
//	chose = head;
//	chose->activ = true;
//}
//template <typename T>
//T* DataBase<T>::GetChose()
//{
//	if (chose != NULL && chose->data != NULL)
//		return chose->data;
//	if (chose != NULL && chose->data == NULL)
//		DeleteChose();
//	return new T();
//}
//template <typename T>
//void DataBase<T>::Change(T* t)
//{
//	delete chose->data;
//	chose->data = t;
//}
