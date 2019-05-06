#pragma once

#include <iostream>
#include <boost/shared_ptr.hpp>

#include "ExposeClasses.h"

struct APointer 
{
	static APointer* create()
	{ 
		return new APointer;
	}

	static boost::shared_ptr<APointer> createSP()
	{ 
		return boost::shared_ptr<APointer>(new APointer);
	}

	std::string hello() 
	{ 
		return "Hello, is there anybody in there?";
	}

	World const& GetWorld() const
	{
		return w;
	}

private:
	World w;
};