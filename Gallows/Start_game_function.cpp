#include "Start_game_function.h"


void startGame(const string SECRET_WORD)
{
	short playerMistakes = 0; // ошибки игрока
	const short MAX_MISTAKES = 8; // максимальное количество ошибок

	string userAnswer(SECRET_WORD.size(), '-'); // для отображения скрытого слова символами "-"

	string usedLetters = "";
	char userLetter;

	cout << "\t\tИгра началась!" << endl;
	clock_t start = clock();//начало отсчета времени

	while (playerMistakes < MAX_MISTAKES)
	{
		enterCorrectGuess(&userAnswer, SECRET_WORD, &userLetter, &usedLetters);

		if (userAnswer == SECRET_WORD)
		{
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			win(playerMistakes, SECRET_WORD,seconds);
			break;
		}

		else if (isLetterInWord(SECRET_WORD, userLetter))
		{
			system("cls");
			cout << "Верно, " << userLetter << " есть в слове!" << endl;
			userAnswer = addLetterToAnswer(SECRET_WORD, userLetter, userAnswer);
		}
		else
		{
			system("cls");
			cout << "Неверно, " << userLetter << " нет в слове!" << endl;
			cout << "Количество ошибок = " << ++playerMistakes << endl;
		}

		if (isWin(userAnswer, SECRET_WORD))
		{
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			win(playerMistakes, SECRET_WORD,seconds);
			break;
		}
	}

	if (playerMistakes == MAX_MISTAKES)
	{
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		lose(SECRET_WORD,seconds);
	}
}

