#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>//��� ������������� sort
#include"Message.h"
#include"Message.h"


using namespace std;
using namespace sf;

Text text;


vector<int>vec;

sf::RenderWindow window;




//............................������� ������+ �����(��� ������������ text...)...............................................
void gluing(string str,int number)
{
	for (int i = 0; i < 10; i++)
	{
		std::ostringstream playerScoreString;    // �������� ����������
		playerScoreString << number;		//������� � ��� ����� �����, �� ���� ��������� ������
		text.setString(str + playerScoreString.str());//������ ������ ������ � �������� �������������� ���� ������ ������� .str() 
	}
}
//...............................................................................................


//.................................������ � ��������� � ��������� ������� �������� �� �������..............


void read()//������ �� �����
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
void write()//������ � ����
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

void recordStatistics(int temp)//���������� � ������� ���������� ������� �����
{
	if (vec.size() == 0)
	{
		vec.push_back(temp);//��������� �����
	}
	if (temp > vec.back())
	{
		vec.pop_back();//������� ��������� ������� �������
		vec.push_back(temp);//��������� �����
		sort(vec.begin(), vec.end(), std::greater<int>());//��������� ������
	}
	write();//����������
	
}

//........................................................................................................................


