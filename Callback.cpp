#include "stdafx.h"
#include "Callback.h"

#include <iostream> 

const string TestCallBack(const string& szParam, object pyCallBack, object obj)
{

	//Python�д��ݵĲ�����C++�п���ֱ��ʹ��  
	std::cout << szParam << std::endl;
	{
		PyLock _pylock;
		pyCallBack("C++ 2 Python.",obj);
	}
	std::string rnt = "hello";
	return rnt;
}


World exClass(object x)
{
	World wp = extract<World>(x);
	std::cout << wp.greet() << std::endl;
	wp.msg = "has changed by c++";
	wp.nameV.push_back("A");
	wp.nameV.push_back("B");
	return wp;
}