// PYWrapper.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

char const* greet()
{
	return "hello, world";
}

BOOST_PYTHON_MODULE(Test)
{
	using namespace boost::python;
	def("greet", greet);
}

