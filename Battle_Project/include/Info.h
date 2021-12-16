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

//Message msg;
//RenderWindow mWindow;
//Font font;
//sf::Font font1, font2, font3, font4, font5, font6, font7, font8, font9, font10;
Text text, text1, text2, text3, text4, text5, text6, text7, text8, text9, text10;


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



////.........................склейка строка+ число + строка...............................................
//void strPlusNumPlusStr( string textNum,string str1, int number, string str2, int x, int y)
//{
//	Text textNum;
//	std::ostringstream playerScoreString;    // объ€вили переменную
//	playerScoreString << number;		//занесли в нее число очков, то есть формируем строку
//	text.setString(str1 + playerScoreString.str()+str2);//задаем строку тексту и вызываем сформированную выше строку методом .str() 
//}
////.............................................................................................................


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
	cout << "теперь вектор такой" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}

//........................................................................................................................


