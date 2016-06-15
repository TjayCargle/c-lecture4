#pragma once
#include "Base.h"
enum WaveMovement{ LeftToRight, TopToBottom, RightToLeft, BottomToTop, TheMax };
class Game
{
private:
	vector<Base*> gameObjects;
	vector<int> scoreList;
	int score = 0;
	int leftBorder = 10;
	int rightBorder = Console::WindowWidth() - 10;
	int topBorder = 2;
	int bottomBorder = Console::WindowHeight() - 2;

	float waitTime = 0;
	int   FenceCountdown = 400;
	int   fenceAmount = 0;
	int   FenceRange = 0;
	bool  play = false;
	int   waves = 0;
	float increaseSpeed = 0;
	int randomOpening;
	WaveMovement aMovement = (WaveMovement)0;
	int  playSpeed = 100;
	bool pause = false;
	bool inAMenu = false;
	void NextWave();
	void SetupWave();
	void CacluateWave(int minRange, int maxRange, int axis, bool left, int startPos,int  aSpeed, bool setaX);
	
public:
	//Constructors
	Game();
	//Getters
	bool isPlaying() { return play; }
	bool isPaused() { return pause; }
	int GetPlaySpeed() const { return playSpeed; }
	float GetIncSpeed() const { return increaseSpeed; }
	int GetScore() const { return score; }
	int GetListSize() const { return (int)scoreList.size(); }
	//Setters
	void playGame( bool _play) { play = _play; }
	void pauseGame(bool _pause) { pause = _pause; }
	void SetPlaySpeed(int _anSpeed) { playSpeed = _anSpeed; }
	void SetIncSpeed(float _anSpeed) { increaseSpeed = _anSpeed; }
	void SetScore(int _aScore) { score = _aScore; }
	//Changers
	void Update();
	void Render();
	void GameOver();
	void SaveScores(int _amount);
	void LoadScores();
	void LoadScoresInBinary();
	void ResetGame();
	void DisplayScores();
	
	
	
	
	~Game();
};

