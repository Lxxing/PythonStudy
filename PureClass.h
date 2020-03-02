#pragma once

#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/python/call.hpp>

using namespace boost::python;

// Class with one pure virtual function
struct P
{
	virtual ~P() {}
	virtual char const* f() = 0;
	char const* g() { return "P::g()"; }
};

struct PCallback : P, wrapper<P>
{
	char const* f()
	{
		return this->get_override("f")();
	}
};

// Class with one non-pure virtual function
struct A
{
	virtual ~A() {}
	virtual char const* f(std::string a) { return "A::f()"; }


};

struct ACallback : A, wrapper<A>
{
	char const* f(std::string a)
	{
		if (override ft = this->get_override("f"))
			return ft(a);
		return A::f(a);
	}

	char const* default_f(std::string a) { return this->A::f(a); }
};
