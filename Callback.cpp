#include "stdafx.h"
#include "Callback.h"

#include <iostream> 

int TestCallBack(const string& szParam, object pyCallBack)
{

	//Python�д��ݵĲ�����C++�п���ֱ��ʹ��  
	std::cout << szParam << std::endl;
	{
		PyLock _pylock;
		pyCallBack("C++ 2 Python.");
	}

	return 0;
}