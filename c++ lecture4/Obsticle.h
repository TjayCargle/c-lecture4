#pragma once
#include "Base.h"

class Obsticle :public Base
{
private:
	int xSpeed = 0;
	int ySpeed = 0;


public:
	//Constructors
	Obsticle();
	Obsticle(int _anX, int _anY, const char* const _anSymbol, ConsoleColor _anColor);

	//Getters
	int GetXSpeed() const { return xSpeed; }
	int GetYSpeed() const { return ySpeed; }

	//Setters
	void SetXSpeed(int _anSpeed) { xSpeed = _anSpeed; }
	void SetYSpeed(int _anSpeed) { ySpeed = _anSpeed; }

	void Update();

	
	
	~Obsticle();
};

