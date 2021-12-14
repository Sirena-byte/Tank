#include<SFML/Graphics.hpp>
#include<iostream>
#include"bonus.h"

using namespace sf;
using namespace std;

Bonus::Bonus()
{
	//gameTime = 0;
	createObjectForMap = 0;
	randomElementX = 0;
	randomElementY = 0;
	countBonus = 5;
	bonus = 0;
	time = clock.getElapsedTime().asMicroseconds();
	mTexture.loadFromFile("media/bonus3.png");
	mTexture.setSmooth(true);//сглаживание текстуры
	mSprite.setTexture(mTexture);
}

void Bonus::randomeGenerate()//поиск рандомных координат
{
	srand((0));
	
	
		randomElementX = 1 + rand() % 501;
		randomElementY = 1 + rand() % 501;;
		cout << "random coordinate= " << randomElementX << " " << randomElementY << endl;
		
		//mSprite.setPosition(randomElementX, randomElementY);//задаем позицию

		
	
}

void Bonus::TimerBonus()//расстановка через выстановленое время
{
	
	createObjectForMap += time;
	if (createObjectForMap > 25000+ rand()% 501)
	{
		BonusDraw();//рисуем 
	
		createObjectForMap = 0.f;
	}
	return;
}

void Bonus::BonusDraw()//отрисовка бонуса
{

	switch (bonus)
	{
	case 0: mSprite.setTextureRect(sf::IntRect(0, 0, 15, 15));break;
	case 1: mSprite.setTextureRect(sf::IntRect(15, 0, 15, 15));break;
	case 2: mSprite.setTextureRect(sf::IntRect(30, 0, 15, 15));break;
	default: break; 
	}
	cout << " bonus" << bonus<< endl;
	randomeGenerate();
	mSprite.setPosition(randomElementX, randomElementY);//задаем позицию
	window.draw(mSprite);
}