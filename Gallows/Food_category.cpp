#include "Food_category.h"

namespace foodCategory
{
	void startLevel()
	{
		system("cls");


		vector<string>foodWords;
		foodWords.push_back("������");
		foodWords.push_back("�������");
		foodWords.push_back("������");
		foodWords.push_back("�����");
		foodWords.push_back("�������");
		foodWords.push_back("����");
		foodWords.push_back("�������");
		foodWords.push_back("����");
		foodWords.push_back("����������");
		foodWords.push_back("���������");
		foodWords.push_back("�������");

		random_shuffle(foodWords.begin(), foodWords.end());

		const string SECRET_WORD = foodWords[0];

		startGame(SECRET_WORD);
	}
};
