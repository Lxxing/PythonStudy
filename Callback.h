#ifndef Callback_h__
#define Callback_h__

#include <string>
#include <boost/python.hpp>

#include "ExposeClasses.h"

using namespace std;

using namespace boost::python;


//GILȫ�����򻯻�ȡ��,���ڰ���C++�̻߳��GIL�����Ӷ���ֹpython����  

class PyLock
{
private:

	PyGILState_STATE gil_state;

public: 

	PyLock()
	{
		gil_state = PyGILState_Ensure();
	}
	~PyLock()
	{
		PyGILState_Release(gil_state);
	}
};

const string TestCallBack(const string& szParam, object pyCallBack, object obj);

World exClass(object x);

#endif // Callback_h__
