#ifndef ExposeClasses_h__
#define ExposeClasses_h__

#include "stdafx.h"
#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

struct World
{
	World(std::string msg) : msg(msg) {} // added constructor
	void set(std::string msg) { this->msg = msg; }
	std::string greet() { return msg; }
	std::string msg;
};

struct Var
{
	Var(std::string name) : name(name), value() {}
	std::string const name;
	float value;
};

struct Num
{
	Num() ;
	float get() const ;
	void set(float value) ;
};

#endif // ExposeClasses_h__

