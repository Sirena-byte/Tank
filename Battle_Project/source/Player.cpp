#include <SFML/Window/Keyboard.hpp>
#include "Player.h"
#include <Map.h>
#include"Application.h"
#include<fstream>
#include<iostream>


using sf::Keyboard;
using namespace std;

Player::Player()
    : Tank(244, 600, 39, 39, "media/playerSprites.png") {//инициализация игрока
    playerScore = 0;//очки игрока
    //record.reserve(10);//зарезервировала место на 10 ячеек
   
  //recordPointLast = 0;
   
    //temp = 0;


    playerLife = 1;
}

void Player::move(const sf::Int64& time) {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        mDir = 1;
        mSpeed = 0.11f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        mDir = 0;
        mSpeed = 0.11f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        mDir = 3;
        mSpeed = 0.11f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        mDir = 2;
        mSpeed = 0.11f;
    }

    switch (mDir) {
    case 0:
        mDx = mSpeed;//направление вправо
        mDy = 0;
        break;

    case 1:
        mDx = -mSpeed;//влево
        mDy = 0;
        break;

    case 2:
        mDx = 0;
        mDy = mSpeed;//вверх;
            break;

    case 3:
        mDx = 0;
        mDy = -mSpeed;//вниз
        break;
    }
    if (mCollision) tank_interaction();//если столкновение с танком
    mX += mDx * time;
    mY += mDy * time;
}

void Player::update(const sf::Int64& time, Map& map, const bool& collision) {
    mCollision = collision;
    move(time);

    mSpeed = 0.f;//скорость
    mSprite.setPosition(mX, mY);//начальная позиция
    animate(time);//анимация
    map_interaction(map);//взаимодействие с картой
    interactionBonus(map);

    bullet.update(map, time, mX, mY, mDir);//инициализация пули
    if (!bullet.present)//если не стреляем
        if (Keyboard::isKeyPressed(Keyboard::Space)) {//если нажат пробел
            bullet.timeBeforeShot += time;
            if (bullet.timeBeforeShot > 10.f) {//задержка между пулями
                bullet.present = true;//стреляем
                bullet.timeBeforeShot = 0.f;//перезаряжаем))
            }
        }
}

void Player::interactionBonus(Map &map)//........................................................
{
        for (int i = mY / 24; i < (mY + mHeight) / 24; ++i)
            for (int j = mX / 24; j < (mX + mWidth) / 24; ++j) {
                char tile = map.get_tile(i, j);

                
                if (tile == '1' || tile == '2' || tile == '3')
                {
                    std::cout << "bonus!!" << std::endl;
                    map.break_wall(i,j);
                }
            }

    }
