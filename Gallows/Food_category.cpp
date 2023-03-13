#include "Food_category.h"

namespace foodCategory
{
	void startLevel()
	{
		system("cls");


		vector<string>foodWords;
		foodWords.push_back("аспцеп");
		foodWords.push_back("ъхвмхжю");
		foodWords.push_back("нцспеж");
		foodWords.push_back("кхлнм");
		foodWords.push_back("йнркерю");
		foodWords.push_back("укеа");
		foodWords.push_back("онлхднп");
		foodWords.push_back("кюил");
		foodWords.push_back("цпеиотпсйр");
		foodWords.push_back("лнпнфемне");
		foodWords.push_back("юапхйня");

		random_shuffle(foodWords.begin(), foodWords.end());

		const string SECRET_WORD = foodWords[0];

		startGame(SECRET_WORD);
	}
};
