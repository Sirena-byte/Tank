#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Tank.h"
#include<vector>
#include<iostream>

class Player : public Tank {
public:
    Player();
    void interactionBonus(Map& map);
    void move(const sf::Int64 &time);
    void update(const sf::Int64 &time, Map &map, const bool &collision);
    //void fillingRecordVector();//запилняем вектор

    
    int playerScore;//текущие очки
   


    int playerLife;
    int level;
  public:  
    //int recordPointLast;//последний рекорд списка
    //std::vector<int>record;//вектор для хранения рекордов
    
};
