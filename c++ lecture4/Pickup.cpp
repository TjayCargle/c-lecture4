#include "stdafx.h"
#include "Pickup.h"


Pickup::Pickup()
{
}

Pickup::Pickup(int _anX, int _anY, const char * const _anSymbol, ConsoleColor _anColor): Base(_anX, _anY, _anSymbol, _anColor)
{
}

void Pickup::Update()
{
	float dx = 0;
	float dy = 0;




	if (getX() + dx >= 0 && getX() + dx < Console::WindowWidth())
	{
		int newx = getX() + dx;
		setX(newx);
	}
	else if (getX() + dx < 0)
	{
		int newx = Console::WindowWidth() - 1;
		setX(newx);
	}



	if (getY() + dy >= 0 && getY() + dy < (int)Console::WindowHeight())
	{
		int newy = getY() + dy;
		setY(newy);
	}
	else if (getY() + dy < 0)
	{
		int newy = Console::WindowHeight() - 1;
		setY(newy);
	}


	
}


Pickup::~Pickup()
{
}
