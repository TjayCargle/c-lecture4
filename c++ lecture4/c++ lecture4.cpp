// c++ lecture4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	//Also need this for memory leak code stuff
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);

	
	Console::SetCursorPosition((Console::WindowWidth() / 2) - 12, Console::WindowHeight() / 2);
	cout << "Press Enter to Play Game";
	Console::SetCursorPosition((Console::WindowWidth() / 2) - 6, (Console::WindowHeight() / 2) - 2);
	cout << "Money Cha$ers";
	cin.get();

	Console::EOLWrap(false);
	Console::BackgroundColor(White);
	Game* theGame = new Game();
	theGame->playGame(true);

	
	while (theGame->isPlaying() == true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			theGame->GameOver();
			break;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			if(theGame->isPaused() == false)
			theGame->pauseGame(true);
			else
				theGame->pauseGame(false);
			
		}
		Console::Lock(true);

		system("cls");

		theGame->Update();
		theGame->Render();

		Console::Lock(false);
		Sleep(theGame->GetPlaySpeed());

	
	}
	system("cls");
	Console::ForegroundColor(Red);
	Console::SetCursorPosition(Console::WindowWidth() / 2, Console::WindowHeight() / 2 - 1);
	cout << "GameOver! \n";
	Console::ForegroundColor(Black);
	Console::SetCursorPosition((Console::WindowWidth() / 2) - 15, Console::WindowHeight() / 2);
	cout << "Would you like to see your scores?";
	Console::SetCursorPosition((Console::WindowWidth() / 2) - 9, (Console::WindowHeight() / 2) + 1);
	cout << "1: Yes \t 2: No";
	Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
	int num = -69;
	do
	{
		if (cin >> num && num < 3 && num >= 1)
		{
			if (num == 1)
			{
				system("cls");
				cout << "Your scores: \n";
				theGame->DisplayScores();
				
				Console::SetCursorPosition((Console::WindowWidth() / 2) - 25, Console::WindowHeight() / 2);
				cout << "Would you like to SAVE your scores from this playthrough???";
				Console::SetCursorPosition((Console::WindowWidth() / 2) - 9, (Console::WindowHeight() / 2) + 1);
				cout << "1: Yes \t 2: No";
				Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
				int num2 = -69;
				do
				{
						if (cin >> num2 && num2 < 3 && num2 >= 1)
						{
							if (num2 == 1)
							{
								int num3 = -69;
								int maxAmount = theGame->GetListSize();
								do
								{
									system("cls");
									theGame->DisplayScores();
									Console::SetCursorPosition((Console::WindowWidth() / 2 )- 15, Console::WindowHeight() / 2);
									cout << "How many scores would you like to save?";
									Console::SetCursorPosition((Console::WindowWidth() / 2) - 15, (Console::WindowHeight() / 2) + 1);
									cout << "Cannot exceed amount of scores";
									Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
									if (cin >> num3 && num3 >0 && num3 <(maxAmount +1))
									{
										    system("cls");
											theGame->SaveScores(num3);
											
											Console::SetCursorPosition((Console::WindowWidth() / 2 )- 8, Console::WindowHeight() / 2);
											cout << "Scores Saved!";
											cin.ignore(INT_MAX, '\n');
											cin.get();
											break;										
										
									}
									else
									{
										system("cls");
										Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) - 1);
										cout << "Uh, try again \n";
										cin.clear();
										cin.ignore(INT_MAX, '\n');
										theGame->DisplayScores();
										Console::SetCursorPosition((Console::WindowWidth() / 2) - 15, Console::WindowHeight() / 2);
										cout << "How many scores would you like to save?";
										Console::SetCursorPosition((Console::WindowWidth() / 2) - 15, (Console::WindowHeight() / 2) + 1);
										cout << "Cannot exceed amount of scores";
										Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
										Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
									}

								} while (true);
								break;

							}
							else
							{
							break;
							}
							
						}
						else
						{
							system("cls");
							Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) - 1);
							cout << "Uh, try again \n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cout << "Your scores: \n";
							theGame->DisplayScores();

							Console::SetCursorPosition((Console::WindowWidth() / 2) - 25, Console::WindowHeight() / 2);
							cout << "Would you like to SAVE your scores from this playthrough???";
							Console::SetCursorPosition((Console::WindowWidth() / 2) - 9, (Console::WindowHeight() / 2) + 1);
							cout << "1: Yes \t 2: No";
							Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
							Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
						}
					

				} while (true);

				break;
			}
			else
			{
				system("cls");
				Console::SetCursorPosition((Console::WindowWidth() / 2) - 30, Console::WindowHeight() / 2);
				cout << "Would you like to LOAD your scores from  a last playthrough???";
				Console::SetCursorPosition((Console::WindowWidth() / 2) - 9, (Console::WindowHeight() / 2) + 1);
				cout << "1: Yes \t 2: No";
				Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
				int num4 = -69;
				do
				{
					

					if (cin >> num4 && num4 < 3 && num4 >= 1)
					{
						if (num4 == 1)
						{
							system("cls");
							cout << "From last text playthrough: \n";
							theGame->LoadScores();
							theGame->DisplayScores();
							cout << "\nFrom last binary playthrough: \n";
							theGame->LoadScoresInBinary();
							theGame->DisplayScores();
							cin.ignore(INT_MAX, '\n');
							cin.get();
							break;
						}
						else
						{
							break;
						}
					}
					else
					{
						system("cls");
						Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) - 1);
						cout << "Uh, try again \n";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						Console::SetCursorPosition((Console::WindowWidth() / 2) - 30, Console::WindowHeight() / 2);
						cout << "Would you like to LOAD your scores from  a last playthrough???";
						Console::SetCursorPosition((Console::WindowWidth() / 2) - 9, (Console::WindowHeight() / 2) + 1);
						cout << "1: Yes \t 2: No";
						Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
						Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
					}

				} while (true);
				break;
			}
		
		}
		else
		{
			system("cls");
			Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) - 2);
			cout << "Uh, try again \n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			Console::SetCursorPosition(Console::WindowWidth() / 2, Console::WindowHeight() / 2 - 1);
			Console::ForegroundColor(Red);
			cout << "GameOver! \n";
			Console::ForegroundColor(Black);
			Console::SetCursorPosition((Console::WindowWidth() / 2) - 15, Console::WindowHeight() / 2);
			cout << "Would you like to see your scores?";
			Console::SetCursorPosition((Console::WindowWidth() / 2) - 9, (Console::WindowHeight() / 2) + 1);
			cout << "1: Yes \t 2: No";
			Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
			Console::SetCursorPosition(Console::WindowWidth() / 2, (Console::WindowHeight() / 2) + 2);
		}

	} while (true);

	cin.ignore(INT_MAX, '\n');
	delete theGame;
	system("cls");
	system("pause");

	

	




    return 0;
}

