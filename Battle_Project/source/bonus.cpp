#include<SFML/Graphics.hpp>
#include<iostream>
#include"bonus.h"

using namespace sf;
using namespace std;

Bonus::Bonus()
{
	gameTime = 0;
	createObjectForMap = 0;
	randomElementX = 0;
	randomElementY = 0;
	countBonus = 5;
}

void Bonus::randomeGenerate(const sf::Int64& time)//����� ��������� ���������
{
	srand((0));
	
	
		randomElementX = 1 + rand() % 501;
		randomElementY = 1 + rand() % 501;;
		cout << "random coordinate= " << randomElementX << " " << randomElementY << endl;
		cout << " time" << time << endl;
		countBonus--;
		if(countBonus <= 0)
		{
			return;
		}
	
}

void Bonus::TimerBonus(const sf::Int64& time)//����������� ����� 3 �������
{
	clock.getElapsedTime().asMicroseconds();
	createObjectForMap += time;
	if (createObjectForMap > 25000+ rand()% 501)
	{
		randomeGenerate(time);
		createObjectForMap = 0.f;
	}
	return;
}