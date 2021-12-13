#pragma once
#include"Map.h"
using namespace sf;
class Bonus
{
private:
	Clock clock;
	Clock gameTimerClock;

	int gameTime;//0
	int createObjectForMap;//0
	int randomElementX;
	int randomElementY;
	int countBonus;

	
	Image image;
	Texture texture;
	Sprite sprite;


	public:
		Bonus();
		void randomeGenerate(const sf::Int64& time);
		void TimerBonus(const sf::Int64& time);
	

	
};


