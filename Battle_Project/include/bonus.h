#pragma once
#include"Map.h"
using namespace sf;
class Bonus
{
private:
	Clock clock;
	Clock gameTimerClock;

	//int gameTime;//������� �����
	int createObjectForMap;//���������� �������
	int randomElementX;//��������� ���������� �� �
	int randomElementY;//��������� ���������� �� �
	int countBonus;//���������� �������
	int bonus;
	
	

	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::RenderWindow window;
	sf::Int64 time;
	public:
		Bonus();
		void randomeGenerate();//��������� ���������
		void TimerBonus();//������� ������
		void BonusDraw();//��������� �������
	

	
};


