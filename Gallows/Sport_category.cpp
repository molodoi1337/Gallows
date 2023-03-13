#include "Sport_category.h"

namespace sportCategory
{
	void startLevel()
	{
		system("cls");

		vector<string>sportWords;
		sportWords.push_back("унййеи");
		sportWords.push_back("тсранк");
		sportWords.push_back("аюяйеранк");
		sportWords.push_back("окюбюмхе");
		sportWords.push_back("йюпюре");
		sportWords.push_back("цюмданк");
		sportWords.push_back("дгчдн");
		sportWords.push_back("оюсщпкхтрхмц");
		sportWords.push_back("анпэаю");
		sportWords.push_back("реммхя");


		random_shuffle(sportWords.begin(), sportWords.end());

		const string SECRET_WORD = sportWords[0];

		startGame(SECRET_WORD);
	}
};