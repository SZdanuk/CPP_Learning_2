#include "Inheritance.h"
#include <iostream>

namespace printerconstants
{
	const std::string BASIC = "Basic::";
	const std::string DERIVED = "Derived::";
	const std::string CALLED { "called" };
	const std::string MOVE{ "move" };
	const std::string COPY{ "copy" };
}


void Basic::printer(std::string msg1, std::string msg2, std::string msg3)
{
	std::cout << msg1 << msg2 << " " << msg3 << std::endl;
}

Basic::Basic()
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
}

Basic::Basic(const Basic&) noexcept
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
}

Basic::Basic(Basic&&) noexcept
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
}

Basic& Basic::operator=(Basic&& other) noexcept
{
	printer(printerconstants::BASIC, __func__, printerconstants::MOVE);
	return *this;
}

Basic& Basic::operator=(const Basic& other) noexcept
{
	printer(printerconstants::BASIC, __func__, printerconstants::COPY);
	return *this;
}

Basic::~Basic() noexcept
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
}

Derived::Derived()
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
}

Derived::~Derived()
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
}

void Basic::myFunc(int val1, int val2)
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
};

void Basic::myFunc2(int val1, int val2)
{
	printer(printerconstants::BASIC, __func__, printerconstants::CALLED);
};

void Derived::myFunc(int val1, int val2)
{
	printer(printerconstants::DERIVED, __func__, printerconstants::CALLED);
};


void Derived::myFunc(int val1, bool val2) 
{
	printer(printerconstants::DERIVED, __func__, printerconstants::CALLED);
};

void Derived::myFunc2(int val1, int val2)
{
	printer(printerconstants::DERIVED, __func__, printerconstants::CALLED);
};
