#ifndef Callback_h__
#define Callback_h__

#include <string>
#include <boost/python.hpp>

using namespace std;

using namespace boost::python;


//GILȫ�����򻯻�ȡ�ã�  

//���ڰ���C++�̻߳��GIL�����Ӷ���ֹpython����  

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

int TestCallBack(const string& szParam, object pyCallBack);

#endif // Callback_h__
