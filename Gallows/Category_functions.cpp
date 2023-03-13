#include "Category_functions.h"



void enterCorrectGuess(string* userAnswer, const string correctAnswer, char* userLetter, string* usedLetters)
{
	string userWord = "";

	while (true)
	{
		clock_t start = clock();//������ ������� �������
		cout << "���������� �����: " << *userAnswer << endl;
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
				cout << "�� ������ �����" << endl;
			}
		}
		// �����
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
					cout << "�� ��� ������������ ����� " << *userLetter << " !" << endl;
				}
			}
			else
			{
				system("cls");
				cout << "��������� ����� ����������� � ������� �����, � ������ � � �����!" << endl;
			}
		}
	}
}

string enterWord() //���� ����� ��� ������ �������
{
	string guess;
	cout << "������� ����� ��� ���������� �����: ";
	cin >> guess;

	return guess;
}

bool isWord(const string word) //��������,����� ��� ��� �����
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

string wordToWORD(string word)//������� �� ������� �������� � �������
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

bool isFinalDecision(const short userAnswerSize, const short correctAnswerSize) //�������� ����� ������ ������ � ����������� ������
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

bool isLetterUsed(const string usedLetters, const char letter) // �������� �� ����� � ���������� �����(���� ��� ��� ��� ���)
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

void show(const string usedLetters)// ����� �������������� ����
{
	cout << "�� ��� ������������ ��������� �����: " << endl;
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

bool isWordExist(const string word) // �������� �� ������� �������
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

bool isSmallLetter(const char letter)// �������� �� ������ �������
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

bool isBigLetter(const char letter) // �������� �� ������� �������
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

char toUpper(char ch) // ������� � ������� �������
{
	// �������� ������� ���� �������� ������� � ������ �������� - 32 = ���� ������ � ������� ��������
	return (char)(ch - 32);
}



bool isLetterInWord(const string SECRET_WORD, const char letter) //�������� �� ������������� ����� ��������� ������� � ���������� �����
{
	if (SECRET_WORD.find(letter) != string::npos) //static const size_t npos = -1; find ���������� -1 ����� ��������� �� �������
	{
		return true;
	}
	else
	{
		return false;
	}
}

string addLetterToAnswer(const string SECRET_WORD, const char guess, string userAnswer) // ��������� ����� � ����� ������
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

bool isWin(const string answer, const string correctAnswer) // �������� �� ������
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

void win(const short mistakes, const string answer,double time) // ���������� � ������ ��������
{
	system("cls");
	cout << "�� �������� ����� " << answer << " ���������� " << mistakes << " ���! �����������!" << endl<<endl;
	cout << "����� ����������� � ������ : " << time << " " << "������" << endl;
}

void lose(const string answer,double time) // ���������� � ������ ���������
{
	system("cls");
	cout << "�� ���������! ��� ����������� ������ � ��������� ���." << endl;
	cout << "�����, ������� �� �� ������ �������� : " << answer << endl << endl;
	cout << "����� ����������� � ������ : " << time<<" "<<"������" << endl;
}
