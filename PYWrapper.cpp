// PYWrapper.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>

#include "ExposeClasses.h"
#include "Inheritance.h"
#include "Callback.h"

#include <Pydlltest/hello.h>

char const* greet()
{	
	return hello();
}

BOOST_PYTHON_MODULE(PYWrapper)
{
	using namespace boost::python;


	PyEval_InitThreads();
	def("TestCallBack", TestCallBack);

	def("greet", greet);

	class_<World>("World", init<std::string>())
		.def(init<>())
		.def("greet", &World::greet)
		.def("set", &World::set)
		;

	class_<Var>("Var", init<std::string>())
		.def_readonly("name", &Var::name)
		.def_readwrite("value", &Var::value);

	class_<Num>("Num")
		.add_property("rovalue", &Num::get)
		.add_property("value", &Num::get, &Num::set);
}
