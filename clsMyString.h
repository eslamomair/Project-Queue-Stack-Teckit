#pragma once
#include<iostream>
#include <stack>

using namespace std;
class clsMyString
{

	string _Value = "";
	stack <string > MyStak ;
	stack <string > Temp;
	void swap()
	{
		 Temp.swap(MyStak);
	}
	 
public:
	 
	 
	void SetValue(string Value)
	{
		_Value = Value;
		 
		MyStak.push(Value);
	}

	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;


	void Undo()
	{

		 MyStak.pop();

		 
		  for (int i = MyStak.size(); i > 0; i--)
		 {
			 _Value = MyStak.top();
		 } 

	}

	void Redo()
	{

		

	}
};

