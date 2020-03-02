#ifndef ExposeClasses_h__
#define ExposeClasses_h__

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

struct World
{
	World() : msg("Defalut") {} 
	World(std::string msg) : msg(msg) {} // added constructor
	void set(std::string msg) { this->msg = msg; }
	void setP(std::string &msg) { this->msg = msg; }
	std::string greet() { return msg; }
	std::string msg;
	std::vector<std::string> nameV;
};

struct Var
{
	Var(std::string name) : name(name), value() {}
	std::string const name;
	float value;


private:
	//~Var() {}
};

struct Num
{
	Num() :rovalue(1.0),value(2.0){}
	float get() const { return value; }
	void set(float val) { value = val; rovalue = val; }
	float rovalue;
	float value;
};

#endif // ExposeClasses_h__

