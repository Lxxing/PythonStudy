#include "stdafx.h"
#include "Callback.h"

#include <iostream> 

int TestCallBack(const string& szParam, object pyCallBack, object obj)
{

	//Python中传递的参数，C++中可以直接使用  
	std::cout << szParam << std::endl;
	{
		PyLock _pylock;
		pyCallBack("C++ 2 Python.",obj);
	}

	return 0;
}