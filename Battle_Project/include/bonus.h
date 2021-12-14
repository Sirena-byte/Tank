#pragma once
#include"Map.h"
using namespace sf;
class Bonus
{
private:
	Clock clock;
	Clock gameTimerClock;

	//int gameTime;//игровое время
	int createObjectForMap;//переменная таймера
	int randomElementX;//рандомная координата по х
	int randomElementY;//рандомная координата по у
	int countBonus;//количество бонусов
	int bonus;
	
	

	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::RenderWindow window;
	sf::Int64 time;
	public:
		Bonus();
		void randomeGenerate();//генерация координат
		void TimerBonus();//функция таймер
		void BonusDraw();//отрисовка бонусов
	

	
};


