#include "stdafx.h"
#include "Callback.h"

#include <iostream> 

int TestCallBack(const string& szParam, object pyCallBack)
{

	//Python�д��ݵĲ�����C++�п���ֱ��ʹ��  
	std::cout << szParam << std::endl;
	{

		PyLock _pylock;
		pyCallBack("Hello Python, I am is C++");
	}

	return 0;
}