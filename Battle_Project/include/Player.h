#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Tank.h"
#include<vector>
#include<iostream>
//#include"Application.h"

class Player : public Tank {
public:
    Player();
    void interactionBonus(Map& map);
    void move(const sf::Int64 &time);
    void update(const sf::Int64 &time, Map &map, const bool &collision);
   // Application application;

    int playerScore;//текущие очки
    int level;
  
};
