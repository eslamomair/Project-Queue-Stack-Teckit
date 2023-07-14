#pragma once
#include <iostream>
#include  "clsDblLinkedList.h"
using namespace std;

template<class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;
public:

	

	
	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value);

	}

	void Print()
	{
		_MyList.PrintList();
		 
	}




	int  Size()
	{
		return _MyList.Size();
	}


	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void Pop()
	{
		_MyList.DeleteFirstNode();

	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		_MyList.UpdateItem(Index, Value);
	}

	void InsertAfter(short Index, T Value)
	{
		_MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd( value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

	

};

