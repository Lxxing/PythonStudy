#ifndef Callback_h__
#define Callback_h__

#include <string>
#include <boost/python.hpp>

using namespace std;

using namespace boost::python;


//GIL全局锁简化获取用,用于帮助C++线程获得GIL锁，从而防止python崩溃  

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

int TestCallBack(const string& szParam, object pyCallBack, object obj);

#endif // Callback_h__
