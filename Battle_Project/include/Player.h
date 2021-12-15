#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Tank.h"
#include<vector>
#include<iostream>

class Player : public Tank {
public:
    Player();

    void move(const sf::Int64 &time);
    void update(const sf::Int64 &time, Map &map, const bool &collision);
    //void fillingRecordVector();//��������� ������
    

   // vector<int>record;//������ ��� �������� ��������
   


    int playerLife;
    int level;
    int playerScore;//������� ����
    int recordPointLast;//��������� ������ ������
    int temp;//��������� ���������� 
    
};
