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
    //void fillingRecordVector();//запилняем вектор
    

   // vector<int>record;//вектор для хранения рекордов
   


    int playerLife;
    int level;
    int playerScore;//текущие очки
    int recordPointLast;//последний рекорд списка
    int temp;//временная переменная 
    
};
