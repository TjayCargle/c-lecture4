#pragma once
#include "Base.h"
class Pickup :	public Base
{
public:
	Pickup();
	Pickup(int _anX, int _anY, const char* const _anSymbol, ConsoleColor _anColor);
	void Update();
	virtual ~Pickup();
};

