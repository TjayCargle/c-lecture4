#pragma once
#include "Base.h"
class Player :
	public Base
{
public:
	//Constructors
	Player();
	Player(int _anX, int _anY, const char* const _anSymbol, ConsoleColor _anColor);
	
	//Changers
	void Update();

	~Player();
};

