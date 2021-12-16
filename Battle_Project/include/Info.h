#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>//для использования sort
#include"Message.h"


using namespace std;
using namespace sf;

//Message msg;
//RenderWindow mWindow;
//Font font;
//sf::Font font1, font2, font3, font4, font5, font6, font7, font8, font9, font10;
//sf::Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10;


vector<int>vec;



int x = 100;
int num = 1;


//void ff()
//{
//	font.loadFromFile("media/PressStart2P.ttf");
//	Text text("", font, 20);
//	text.setOutlineColor(Color::White);
//	ostringstream infoRecord;
//}

//void printInfo(int x, int y,char str,int infoRec)
//{
//	int y = 100;
//	for (int i = 0; i < 10; i++)
//	{
//		ff();
//		msg.info << mPlayer.playerScore;
//		text.setString( infoRec);//выводим очки игрока
//		text.setPosition(750, y);
//		mWindow.draw(text);
//		y += 20;
//	}
//}





//.................................работа с загрузкой и выгрузкой таблицы рекордов из вектора..............


void read()//чтение из файла
{
	ifstream fin("score.txt");
	if (fin)
	{
		int n;
		while (fin >> n)
			vec.push_back(n);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}

	}
	
	else
		cout << "Error opening file!" << endl;
	fin.close();
	cout << "вектор такой" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}
void write()//запись в файл
{
	ofstream ofile;
	ofile.open("score.txt");
	int n;
	for (int i = 0; i < vec.size(); i++)
	{
		n = vec[i];
		ofile << n << " ";
	}
	ofile.close();
	vec.clear();
}

void recordStatistics(int temp)//передается в функцию переменная текущих очков
{
	if (vec.size() == 0)
	{
		vec.push_back(temp);//добавляем новый
	}
	if (temp > vec.back())
	{
		vec.pop_back();//удаляем последний элемент вектора
		vec.push_back(temp);//добавляем новый
		sort(vec.begin(), vec.end(), std::greater<int>());//сортируем вектор
	}
	write();//записываем
	cout << "теперь вектор такой" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}

//........................................................................................................................


