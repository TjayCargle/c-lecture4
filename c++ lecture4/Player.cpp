#include "stdafx.h"
#include "Player.h"
#define Up GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)
#define Down GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)
#define Left GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)
#define Right GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)

Player::Player()
{
}

Player::Player(int _anX, int _anY, const char * const _anSymbol, ConsoleColor _anColor) : Base( _anX, _anY,  _anSymbol,  _anColor)
{
}

void Player::Update()
{
	int dx = 0;
	int dy = 0;

	if (Up) dy = -1;
	if (Down) dy = 1;
	if (Left) dx = -1;
	if (Right) dx = 1;

	if (dx || dy)
	{
		if (getX() + dx >= 10 && getX() + dx < Console::WindowWidth()-10)
		{
			int newx = getX() + dx;
			setX(newx);
		}
		if (getY() + dy >= 2 && getY() + dy < Console::WindowHeight()-2)
		{
			int newy = getY() + dy;
			setY(newy);
		}
	}
}



Player::~Player()
{
	int c = 0;
}
