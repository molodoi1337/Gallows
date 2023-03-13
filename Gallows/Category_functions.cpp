#include "Category_functions.h"



void enterCorrectGuess(string* userAnswer, const string correctAnswer, char* userLetter, string* usedLetters)
{
	string userWord = "";

	while (true)
	{
		clock_t start = clock();//начало отсчета времени
		cout << "«агаданное слово: " << *userAnswer << endl;
		show(*usedLetters);
		userWord = enterWord();

		if (isWord(userWord))
		{
			if (isFinalDecision(userWord.size(), correctAnswer.size()))
			{
				userWord = wordToWORD(userWord);
				if (isWordExist(userWord))
				{
					if (isWin(userWord, correctAnswer))
					{
						*userAnswer = correctAnswer;
						clock_t end = clock();
						break;
					}
				}
				else
				{	
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					lose(correctAnswer,seconds);
					break;
				}
			}
			else
			{
				system("cls");
				cout << "Ќе верное слово" << endl;
			}
		}
		// буква
		else
		{
			*userLetter = userWord[0];

			if (isLetterExist(*userLetter))
			{
				if (isSmallLetter(*userLetter))
				{
					*userLetter = toUpper(*userLetter);
				}
				if (!isLetterUsed(*usedLetters, *userLetter))
				{
					*usedLetters += *userLetter;
					break;
				}
				else
				{
					system("cls");
					cout << "¬ы уже использовали букву " << *userLetter << " !" << endl;
				}
			}
			else
			{
				system("cls");
				cout << "¬веденна€ буква отсутствует в русском €зыке, а значит и в слове!" << endl;
			}
		}
	}
}

string enterWord() //¬вод буквы или ответа целиком
{
	string guess;
	cout << "¬ведите букву или загаданное слово: ";
	cin >> guess;

	return guess;
}

bool isWord(const string word) //ѕроверка,слово это или буква
{
	if (word.size() != 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string wordToWORD(string word)//ѕеревод из нижнего регистра в верхний
{
	for (int i = 0; i < word.size(); i++)
	{
		if (isSmallLetter(word[i]))
		{
			word[i] = toUpper(word[i]);
		}
	}
	return word;
}

bool isFinalDecision(const short userAnswerSize, const short correctAnswerSize) //проверка длины ответа игрока и правильного ответа
{
	if (userAnswerSize == correctAnswerSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isLetterUsed(const string usedLetters, const char letter) // проверка на букву в загаданном слове(есть она там или нет)
{
	if (usedLetters.find(letter) == string::npos)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void show(const string usedLetters)// вывод использованных букв
{
	cout << "¬ы уже использовали следующие буквы: " << endl;
	cout << usedLetters << endl;
}

bool isLetterExist(const char letter)
{
	if (isSmallLetter(letter))
	{
		return true;
	}
	else if (isBigLetter(letter))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isWordExist(const string word) // проверка на верхний регистр
{
	for (int i = 0; i < word.size(); i++)
	{
		if (isSmallLetter(word[i]))
		{
			return false;
		}
	}
	return true;
}

bool isSmallLetter(const char letter)// проверка на нижний регистр
{
	if ((letter >= -32 && letter <= -1) || letter == -72)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isBigLetter(const char letter) // проверка на верхний регистр
{
	if ((letter >= -64 && letter <= -33) || letter == -88)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char toUpper(char ch) // перевод в верхний регистр
{
	// согласно таблице аски значение символа в нижнем регистре - 32 = этот символ в верхнем регистре
	return (char)(ch - 32);
}



bool isLetterInWord(const string SECRET_WORD, const char letter) //проверка на существовании буквы введенной игроком в загаданном слове
{
	if (SECRET_WORD.find(letter) != string::npos) //static const size_t npos = -1; find возвращает -1 когда подстрока не найдена
	{
		return true;
	}
	else
	{
		return false;
	}
}

string addLetterToAnswer(const string SECRET_WORD, const char guess, string userAnswer) // добавл€ет букву в ответ игрока
{
	for (int i = 0; i < SECRET_WORD.length(); ++i)
	{
		if (SECRET_WORD[i] == guess)
		{
			userAnswer[i] = guess;
		}
	}
	return userAnswer;
}

bool isWin(const string answer, const string correctAnswer) // проверка на выигыш
{
	if (answer == correctAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void win(const short mistakes, const string answer,double time) // вызываетс€ в случае выигрыша
{
	system("cls");
	cout << "¬ы отгадали слово " << answer << " ошибившись " << mistakes << " раз! ѕоздравл€ем!" << endl<<endl;
	cout << "¬рем€ проведенное в сессии : " << time << " " << "секунд" << endl;
}

void lose(const string answer,double time) // вызываетс€ в случае проигрыша
{
	system("cls");
	cout << "¬ы проиграли! ¬ам об€зательно повезЄт в следующий раз." << endl;
	cout << "—лово, которое вы не смогли отгадать : " << answer << endl << endl;
	cout << "¬рем€ проведенное в сессии : " << time<<" "<<"секунд" << endl;
}
