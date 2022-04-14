#pragma once
#include "Note.h"
#include <string>

template <typename T>
class DataBase
{
public:
	Note<T>* head = NULL;
	Note<T>* tail = NULL;
	Note<T>* chose = NULL;
	int Size = 0;

	virtual ~DataBase<T>()
	{
		while (head != NULL)
		{
			Note<T>* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void Add(T* t)
	{
		Note<T>* newt = new Note<T>(t);
		if (head == NULL)
		{
			head = newt;
			chose = head;
			tail = head;
		}
		else
		{
			tail->next = newt;
			newt->prev = tail;
			tail = newt;
		}
		Size++;
	}
	void DeleteChose()
	{
		Note<T>* p = chose->prev;
		Note<T>* n = chose->next;
		delete chose;
		if (p != NULL)
			p->next = n;
		else
			head = n;
		if (n != NULL)
			n->prev = p;
		else
			tail = p;
		chose = head;
		Size--;
	}
	void Delete()
	{
		Note<T>* p = tail->prev;
		delete tail;
		p->next = NULL;
		tail = p;
		Size--;
	}
	void DeleteAll()
	{
		while (head != NULL)
		{
			Note<T>* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void Next()
	{
		if (chose->next != NULL)
			chose = chose->next;
		else
			chose = head;
	}
	void Prev()
	{
		chose->activ = false;
		if (chose->prev != NULL)
			chose = chose->prev;
		else
			chose = tail;
		chose->activ = true;
	}
	void Head()
	{
		if (chose != NULL)
		{
			chose = head;
		}
	}
	T* GetChose()
	{
		if (chose != NULL && chose->data != NULL)
			return chose->data;
		if (chose != NULL && chose->data == NULL)
			DeleteChose();
		return new T();
	}
	void Change(T* t)
	{
		delete chose->data;
		chose->data = t;
	}
	T* GetData()
	{
		T* temp = chose->data;
		chose->data = NULL;
		DeleteChose();
		return temp;
	}
};

