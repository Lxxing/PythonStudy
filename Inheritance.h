#ifndef Inheritance_h__
#define Inheritance_h__

#include "stdafx.h"
#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

using namespace std;
// An abstract base class
class Base : public boost::noncopyable
{
public:
	virtual ~Base() {};
	virtual std::string hello() = 0;
};

// C++ derived class
class CppDerived : public Base
{
public:
	virtual ~CppDerived() {}
	virtual std::string hello() { return "CppDerived Hello from C++!"; }
};

// Familiar Boost.Python wrapper class for Base
struct BaseWrap : Base, boost::python::wrapper<Base>
{
	virtual std::string hello()
	{
#if BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
		// workaround for VC++ 6.x or 7.0, see
		return python::call<std::string>(this->get_override("hello").ptr());
#else
		return this->get_override("hello")();
#endif
	}
};

#endif // Inheritance_h__

