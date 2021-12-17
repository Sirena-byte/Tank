#include <SFML/Graphics.hpp>
#include"Enemy.h"
//#include"bonus.h"
#include<iostream>

using namespace std;


Enemy::Enemy(const float &x, const float &y)
    : Tank(x, y, 39, 39, "media/enemySprites.png"), timeBeforeMoving(0.f), timeBeforeShot(0.f) {

}

void Enemy::move(const sf::Int64 &time) {
    mSpeed = 0.1f;//скорость
    timeBeforeMoving += time;//таймер

    if (timeBeforeMoving > 1000 + rand() % 501) {//отрезок времени
        mDir = rand() % 4;//рандомно выбирается направление
        timeBeforeMoving = 0.f;//обновляется переменная времени
       //mBonus.randomeGenerate(7);//////////////////////////////////////////////////////////////////////
       
        
    }
  

    switch (mDir) {//направление
        case 0:
            mDx = mSpeed;//вправо
            mDy = 0;
            break;

        case 1:
            mDx = -mSpeed;//влево
            mDy = 0;
            break;

        case 2:
            mDx = 0;
            mDy = mSpeed;//вверх
            break;

        case 3:
            mDx = 0;
            mDy = -mSpeed;//вниз
            break;
    }
    if (mCollision) tank_interaction();//если столкновение с танком
    mX += mDx * time;//меняет направленрие
    mY += mDy * time;
}

void Enemy::shoot(const float &time) {
    timeBeforeShot += time;//время между пулями

    if (timeBeforeShot > 2000.f) {
        if (!bullet.present)
            if (rand() % 2)
                bullet.present = true;//стреляет

        timeBeforeShot = 0.f;
        //mBonus.TimerBonus(time);//........................................................................................bonus
    }
}

void Enemy::update(const sf::Int64 &time, Map &map, const bool &collision) {//инициализация врага
    mCollision = collision;
    move(time);

    mSpeed = 0.f;//скорость
    mSprite.setPosition(mX, mY);//место "рождения"
    animate(time);//анимация
    map_interaction(map);//взаимодействие с картой

    bullet.update(map, time, mX, mY, mDir);//инициализация пули
    shoot(time);//стрельба
}
