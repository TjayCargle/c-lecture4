#include "stdafx.h"
#include "Base.h"

#define Up GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)
#define Down GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)
#define Left GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)
#define Right GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)

Base::Base()
{
}

Base::Base(int _anX, int _anY, const char * const _anSymbol, ConsoleColor _anColor)
{
	
	mX = _anX;
	mY = _anY;
	mSymbol = _anSymbol;
	mColor = _anColor;
	
}


void Base::setSymbol(const char * const _anSymbol)
{
	
	mSymbol = _anSymbol;
}

void Base::Update()
{


}

void Base::Render()
{
	Console::ForegroundColor(mColor);
	Console::SetCursorPosition(mX, mY);
	cout << mSymbol;

}

Base::~Base()
{
	
}
