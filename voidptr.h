#pragma once


# include <boost/python/return_opaque_pointer.hpp>
# include <boost/python/def.hpp>
# include <boost/python/module.hpp>
# include <boost/python/return_value_policy.hpp>

static void *test = (void *)78;

void *get()
{
	return test;
}

void *getnull()
{
	return 0;
}

void use(void *a)
{
	if (a != test)
		throw std::runtime_error(std::string("failed"));
}

int useany(void *a)
{
	return a ? 1 : 0;
}