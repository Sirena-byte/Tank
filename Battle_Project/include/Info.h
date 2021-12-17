#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>//дл€ использовани€ sort
#include"Message.h"
#include"Message.h"


using namespace std;
using namespace sf;

Text text;


vector<int>vec;

sf::RenderWindow window;




//............................склейка строка+ число(дл€ формировани€ text...)...............................................
void gluing(string str,int number)
{
	for (int i = 0; i < 10; i++)
	{
		std::ostringstream playerScoreString;    // объ€вили переменную
		playerScoreString << number;		//занесли в нее число очков, то есть формируем строку
		text.setString(str + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
	}
}
//...............................................................................................


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

void recordStatistics(int temp)//передаетс€ в функцию переменна€ текущих очков
{
	if (vec.size() == 0)
	{
		vec.push_back(temp);//добавл€ем новый
	}
	if (temp > vec.back())
	{
		vec.pop_back();//удал€ем последний элемент вектора
		vec.push_back(temp);//добавл€ем новый
		sort(vec.begin(), vec.end(), std::greater<int>());//сортируем вектор
	}
	write();//записываем
	
}

//........................................................................................................................


