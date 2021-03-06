// PYWrapper.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "ExposeClasses.h"
#include "Inheritance.h"
#include "Callback.h"
#include "PureClass.h"
#include "Pointer.h"
#include "voidptr.h"

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


	// vector of strings
	class_<std::vector<std::string> >("StringVec")
		.def(vector_indexing_suite<std::vector<std::string> >())
		;

	class_<World>("World", init<std::string>())
		.def(init<>())
		.def("greet", &World::greet)
		.def("set", &World::set)
		.def("setP", &World::setP)
		.def_readwrite("nameV", &World::nameV)
		;

	class_<Var>("Var", init<std::string>())
		.def_readonly("name", &Var::name)
		.def_readwrite("value", &Var::value)
		;

	class_<Num>("Num")
		.add_property("rovalue", &Num::get)
		.add_property("value", &Num::get, &Num::set);

	class_<PCallback, boost::noncopyable>("P")
		.def("f", pure_virtual(&P::f))
		;

	class_<ACallback, boost::noncopyable>("A")
		.def("f", &A::f, &ACallback::default_f)
		;

	class_<APointer, boost::shared_ptr<APointer>>("APointer")
		.def("create", &APointer::create, return_value_policy<manage_new_object>())
		.staticmethod("create")
		.def("createSP",&APointer::createSP)
		.staticmethod("createSP")
		.def("hello", &APointer::hello)
		.def("GetWorld",&APointer::GetWorld, return_internal_reference<>())
		;
	
	//void*指针
	def("get", &::get, return_value_policy<return_opaque_pointer>());
	def("getnull", &::getnull, return_value_policy<return_opaque_pointer>());
	def("use", &::use);
	def("useany", &::useany);

	//提取c++类
	def("exClass", exClass);

	//
	class_<BaseWrap, boost::noncopyable> base("Base");
}
