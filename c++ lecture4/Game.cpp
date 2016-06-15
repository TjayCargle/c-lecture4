#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Obsticle.h"
#include "Pickup.h"

#define PrepareNextWave                                       \
for (int z = 1; z < (int)gameObjects.size(); z++)             \
{	delete ((Base*)gameObjects[z]);}                          \
gameObjects.resize(1);                                        \
NextWave();SetupWave();                                       \
if (aMovement == 0 || aMovement == 2)                         \
FenceCountdown = 300;                                         \
else{FenceCountdown = 600;}

#define DeleteExtra                                           \
delete ((Base*)gameObjects[i]);                               \
gameObjects.erase(gameObjects.begin() + i);\
i--;

#define SetupBorder 	                                      \
Console::ForegroundColor(Black);                              \
Console::SetCursorPosition(leftBorder -1, 0);                 \
cout << "Score: " << score;                                   \
Console::SetCursorPosition(rightBorder-8, 0);                 \
cout << "Wave: " << waves;                                    \
Console::DrawBox(leftBorder - 1, topBorder - 1, rightBorder - 8, bottomBorder, true);


Game::Game()
{

	gameObjects.push_back(new Player( (int)Console::WindowWidth()/2, (int)Console::WindowHeight()/2, "O", Red));
	NextWave();
	SetupWave();
	
	bool sound = PlaySound(TEXT("snowyheights.wav"), NULL, SND_FILENAME | SND_ASYNC| SND_LOOP);
	
}



void Game::Update()
{
	SetupBorder
	if(inAMenu == false)	
	if (pause == false)
	{
	
		

			Player* temp = dynamic_cast<Player*>(gameObjects[0]);

		if (temp)
		{
			((Player*)gameObjects[0])->Update();
		}


		if (waitTime == 0)
		{
			for (int i = 1; i < (int)gameObjects.size(); i++)
			{
				gameObjects[i]->Update();

				switch (aMovement)
				{
				case LeftToRight:

					if (gameObjects[i]->getX() > rightBorder )
					{
						DeleteExtra
							if (gameObjects.size() < 3)
							{
								PrepareNextWave
							}
					}

					break;
				case TopToBottom:

					if (gameObjects[i]->getY() > bottomBorder )

					{
						DeleteExtra	
							if (gameObjects.size() < 3)
							{
								PrepareNextWave
							}
					}
					

					break;
				case RightToLeft:

					if (gameObjects[i]->getX() < leftBorder )

					{
						DeleteExtra
							if (gameObjects.size() < 3)
							{
								PrepareNextWave
							}
					}
			


					break;
				case BottomToTop:

					if (gameObjects[i]->getY() < topBorder)

					{
						DeleteExtra
							if (gameObjects.size() < 3)
							{
								PrepareNextWave
							}
					}

					break;

				default:
					break;
				}

			}
			if (increaseSpeed <= 2)
			{
				if (aMovement == 0 || aMovement == 2)
					waitTime = (2 - increaseSpeed);
				else
					waitTime = (4 - increaseSpeed);
			}
			else if (playSpeed > 1)
			{
				playSpeed = 100 - waves;
				if (aMovement == 0 || aMovement == 2)
					waitTime = 0;
				else
					waitTime = 4;

			}
		}
		else if (waitTime > 0)
		{
			waitTime--;
		}
		else if (waitTime < 0)
		{
			waitTime = 2;
		}



		for (int i = 1; i < (int)gameObjects.size(); i++)
		{

			Obsticle* temp = dynamic_cast<Obsticle*>(gameObjects[i]);
			Pickup* temp2 = dynamic_cast<Pickup*>(gameObjects[i]);
			if (temp)
			{
				if (gameObjects[0]->getX() == gameObjects[i]->getX() && gameObjects[0]->getY() == gameObjects[i]->getY())
				{
					GameOver();
					break;
				}
			}
			else if (temp2)
			{
				if (gameObjects[0]->getX() == gameObjects[i]->getX() && gameObjects[0]->getY() == gameObjects[i]->getY())
				{
					SetScore(score += 10);
					DeleteExtra
					break;
				}
			}

			

			if (fenceAmount > 0 && FenceCountdown == 0)
			{
				SetupWave();
				fenceAmount--;
				if (aMovement == 0 || aMovement == 2)
					FenceCountdown = 600;
				else
				{
					FenceCountdown = 900;
				}
			}
			else if (FenceCountdown > 0)
			{
				if (waitTime == 0)
					FenceCountdown--;
			}
		}
	}
	else
	{
		Console::ForegroundColor(Black);
		Console::SetCursorPosition(Console::WindowWidth()/2, Console::WindowHeight()/2); cout << "Game Paused";
	}

}

void Game::Render()
{
	if (pause == false)
	{
		for (int i = 0; i < (int)gameObjects.size(); i++)
		{
			gameObjects[i]->Render();
		}
	}
}

void Game::NextWave()
{
	
	srand(time(NULL));
	
	if (waves )//% 3 == 0)
	{
		int num = rand() % TheMax;
	//	srand(time(NULL));
		int xPos = (rand() % rightBorder) +  leftBorder;
		if (xPos < leftBorder || xPos > rightBorder)
		{
			while (xPos < leftBorder || xPos > rightBorder)
			{
				xPos = (rand() % rightBorder) + leftBorder;
			}
		}
		//srand(time(NULL));
		int yPos = (rand() % bottomBorder) + topBorder;
		if (yPos < topBorder || yPos > bottomBorder)
		{
			while (yPos < topBorder || yPos > bottomBorder)
			{
				yPos = (rand() % bottomBorder) + topBorder;
			}
		}


		aMovement = (WaveMovement)num;
		FenceRange++;
		gameObjects.push_back(new Pickup(xPos,yPos, "$", Green));
	}
	
	//gameObjects.resize(1);
	
	for (int i = 0; i < FenceRange; i++)
		fenceAmount++;
	

	//for (fenceAmount; fenceAmount >= 0; fenceAmount--)
	//{
		//SetupWave(0);
		//fenceAmount--;
	//}
	

	if (waves % 2 == 0)
	{
		increaseSpeed ++;
	}
	waves++;
	score+= (1*fenceAmount);
}

void Game::GameOver()
{
	for (int z = 0; z <= (int)gameObjects.size(); z++)
	{
		if (gameObjects.size() > 0)
		{
			delete ((Base*)gameObjects[z]);
			gameObjects.erase(gameObjects.begin() + z);
			z--;
		}
	}

	scoreList.push_back(score);

	ResetGame();
	
}

void Game::SaveScores(int _amount)
{

	ofstream fout;

	cout << "Saving out...\n";
	fout.open("save.txt", ios_base::trunc);

	if (fout.is_open())
	{
		for (int i = 0; i < _amount; i++)
		{
			fout << '\n'  << scoreList[i];
		}
		

		fout.close();
	}
	

	fstream bout;

	bout.open("save.bin", ios_base::out | ios_base::binary);

	if (bout.is_open())
	{
		//bout.write((char*)&infos[0], sizeof(Info) * infos.size());
		bout.write((char*)scoreList.data(), sizeof(int) * scoreList.size());

		bout.close();
	}


}

void Game::LoadScores()
{

	ifstream fin;

	cout << "Reading in...\n";

	fin.open("save.txt");
	if (fin.is_open())
	{
		scoreList.clear();
		int num = -69;
		
		while (!fin.eof())
		{
			fin.ignore(INT_MAX, '\n');

			fin >> num;

			scoreList.push_back(num);
		}
	

		fin.close();
	}
}

void Game::LoadScoresInBinary()
{

	ifstream bin;

	bin.open("save.bin", ios_base::binary);

	if (bin.is_open())
	{
		bin.seekg(0, ios_base::end);
		int count = (int)bin.tellg();
		bin.seekg(0, ios_base::beg);

		count /= sizeof(int);

		scoreList.clear();
		scoreList.resize(count);

		bin.read((char*)&scoreList[0], sizeof(int) * count);

		bin.close();
	}

}

void Game::ResetGame()
{
	Console::Lock(false);

	system("cls");

	inAMenu = true;
	Console::ForegroundColor(Black);
	Console::SetCursorPosition(Console::WindowWidth() / 2, Console::WindowHeight() / 2); 
	cout << "Would you like to play again?\n";
	Console::SetCursorPosition(Console::WindowWidth() / 2,( Console::WindowHeight() / 2)+ 1);
	cout << "1: Yes \t 2: No";
	Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);


	int num = -69;
	do
	{		
		if (cin >> num && num < 3 && num >= 1)
		{
			if (num == 1)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				system("cls");

				inAMenu = false;
				score = 0;
				waitTime = 0;
				FenceCountdown = 400;
				fenceAmount = 0;
				FenceRange = 0;
				waves = 0;
				increaseSpeed = 0;
				playSpeed = 100;
				gameObjects.push_back(new Player((int)Console::WindowWidth() / 2, (int)Console::WindowHeight() / 2, "O", Red));
				NextWave();
				SetupWave();

				num = -69;
			}
			else
			{
				inAMenu = false;
				playGame(false);
			}
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			system("cls");
			Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) - 1);
			cout << "Uh, try again \n";
		
			Console::SetCursorPosition(Console::WindowWidth() / 2, Console::WindowHeight() / 2);
			cout << "Would you like to play again?\n";
			Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 1);
			cout << "1: Yes \t 2: No";
			Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
		
			
		}

	} while (true);
}

void Game::DisplayScores()
{
	Console::ForegroundColor(Black);
	//system("cls");
	
	sort(scoreList.begin(), scoreList.end());
	reverse(scoreList.begin(), scoreList.end());
	for (int j = 0; j < (int)scoreList.size(); j++)
	{
		cout << scoreList[j] << "\n";
	}
}



void Game::SetupWave()
{

	switch (aMovement)
	{
	case LeftToRight:
		CacluateWave(topBorder, bottomBorder, (int)Console::WindowHeight(), true, leftBorder, 1, true);

		break;
	case TopToBottom:
		CacluateWave(leftBorder, rightBorder, (int)Console::WindowWidth(), false, topBorder, 1, false);
	
		break;
	case RightToLeft:
		CacluateWave(topBorder, bottomBorder, (int)Console::WindowHeight(), true, rightBorder, -1, true);
	
		break;
	case BottomToTop:
		CacluateWave(leftBorder, rightBorder, (int)Console::WindowWidth(), false, bottomBorder, -1, false);
		
		break;

	default:

		break;
	}

	


}

void Game::CacluateWave(int minRange, int maxRange, int axis, bool left, int startPos,int aSpeed, bool setaX)
{
	randomOpening = (rand() % axis) + maxRange;
	if (randomOpening < minRange || randomOpening > maxRange)
	{
		while (randomOpening < minRange || randomOpening > maxRange)
		{
			randomOpening = rand() % axis;
		}
	}


	for (int i = minRange; i < maxRange; i++)
	{

		if (i < randomOpening - 1 || i > randomOpening + 1)
		{
		if(left == true)
			gameObjects.push_back(new Obsticle(startPos, i, "X", Blue));
		else
			gameObjects.push_back(new Obsticle(i, startPos, "X", Blue));


		}

	}
	for (int j = 0; j < (int)gameObjects.size(); j++)
	{
		Obsticle* temp = dynamic_cast<Obsticle*>(gameObjects[j]);

		if (temp)
		{
			if(setaX == true)
			((Obsticle*)gameObjects[j])->SetXSpeed(aSpeed);
			else
			{
				((Obsticle*)gameObjects[j])->SetYSpeed(aSpeed);
			}
		}
	}
}

Game::~Game()
{
	
	
}