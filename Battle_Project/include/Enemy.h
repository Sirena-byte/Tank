#pragma once
#include "Tank.h"
//#include"bonus.h"

class Enemy : public Tank {
private:
    float timeBeforeMoving;//время до переезда
    float timeBeforeShot;//время до стрельбы
    //Bonus mBonus;
public:

    Enemy(const float& x, const float& y);//координаты
    Enemy(const Enemy& copy) : Enemy(copy.mX, copy.mY) {}

    void move(const sf::Int64& time);//движение
    void shoot(const float& time);//стрельба
    void update(const sf::Int64& time, Map& map, const bool& collision);//обновление
};
