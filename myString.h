#pragma once
#include <iostream>
#include <string>
using namespace std;
class myString
{
private:
	int len;
	char* str;
public:
	myString()
	{
		cout << this << endl;
		len = 0;
		str = nullptr;
	}
	myString(const char* s)
	{
		std::cout << this << endl;
		len = strlen(s) + 1;
		str = new char[len];
		strcpy_s(str, len, s);
	}
	myString(myString& other)
	{
		cout << this << endl;
		this->len = other.len;
		this->str = new char[this->len];
		strcpy_s(this->str, len * sizeof(char), other.str);
	}


	myString& operator+ (const myString& other)
	{
		if (&other == this)
		{
			return*this;
		}
		this->len = other.len;
		if (str != nullptr)
		{
			delete[] str;
		}
		str = new char[this->len];
		strcpy_s(str, this->len * sizeof(char), other.str);
		return *this;
	}
	void operator()(const char* s)
	{
		if (len != 0)
		{
			delete[]str;
		}
		len = strlen(s) + 1;
		str = new char[len];
		strcpy_s(str, len * sizeof(char), s);
	}
};

