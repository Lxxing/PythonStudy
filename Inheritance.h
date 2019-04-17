#ifndef Inheritance_h__
#define Inheritance_h__

#include "stdafx.h"
#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

using namespace std;

class CBase
{
public:
	CBase() { }
	virtual ~CBase() { }

	void myBase()
	{
		cout << "CBase::myBase" << endl;
	}
};

class CDerive : public CBase
{
public:
	CDerive() { }
	~CDerive() { }

	void myDerive()
	{
		cout << "CDerive::myDerive" << endl;
	}
};


struct base
{
	virtual ~base() {};
	int a;
};

struct derive : base
{
public:
	int b;

};

#endif // Inheritance_h__

