#include "Sport_category.h"

namespace sportCategory
{
	void startLevel()
	{
		system("cls");

		vector<string>sportWords;
		sportWords.push_back("������");
		sportWords.push_back("������");
		sportWords.push_back("���������");
		sportWords.push_back("��������");
		sportWords.push_back("������");
		sportWords.push_back("�������");
		sportWords.push_back("�����");
		sportWords.push_back("������������");
		sportWords.push_back("������");
		sportWords.push_back("������");


		random_shuffle(sportWords.begin(), sportWords.end());

		const string SECRET_WORD = sportWords[0];

		startGame(SECRET_WORD);
	}
};