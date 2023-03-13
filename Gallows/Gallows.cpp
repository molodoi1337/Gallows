#include <iostream>
#include <Windows.h>
#include <time.h>

#include "Functions.h"
#include "Food_category.h"
#include "Sport_category.h"

using namespace std;

enum GameActions
{
	CHECK_RULES = 1,
};

enum WordCategories
{
	FOOD_CATEGORY = 1,
	SPORT_CATEGORY = 2,
	RANDOM_CATEGORY = 3
};

int main()
{
	srand(time(0));
	//Задает кодировку ввода и вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t\t\t Игра Виселица" << endl;

	int gameAction = atoi(enterAction().c_str());//c_str - перевод в с строку.(const char*)


	if (gameAction == CHECK_RULES)
	{
		showGameRules();
		system("pause");
		system("cls");
	}

	short wordCategory = atoi(enterCategory().c_str());//тоже самое что и в 31

	if (wordCategory == RANDOM_CATEGORY)
	{
		wordCategory = getRandomCategory();
	}
	if (wordCategory == FOOD_CATEGORY)
	{
		foodCategory::startLevel();
	}
	else if (wordCategory == SPORT_CATEGORY)
	{
		sportCategory::startLevel();
	}


	system("pause");
	return 0;
}