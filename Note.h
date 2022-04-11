#pragma once
template <class T>
class Note
{
public:
	T* data = NULL;
	Note<T>* next = NULL;
	Note<T>* prev = NULL;
	bool activ = false;
	Note<T>() {}
	Note<T>(T* value)
	{
		data = value;
	}
	~Note<T>()
	{
		delete data;
	}
};

