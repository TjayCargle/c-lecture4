#pragma once

class Base
{
private:

	int mX;
	int mY;
	string mSymbol = "y";
	ConsoleColor mColor;
public:
	//Constructors
	Base();
	Base(int _anX, int _anY, const char* const _anSymbol, ConsoleColor _anColor );
	//Getters
	int getX() const { return mX; }
	int getY() const { return mY; }
	const char * const getSymbol() const{ return mSymbol.c_str(); }
	ConsoleColor getColor() const { return mColor; }

	//Setters
	void setX(int _anX)  { mX = _anX; }
	void setY(int _anY)  { mY = _anY; }
	void setSymbol(const char* const _anSymbol);
	void setColor(ConsoleColor _anColor)  { mColor = _anColor; }

	//Changers
	virtual	void Update();
	virtual	void Render();

	//Destructor
	virtual ~Base();
};

