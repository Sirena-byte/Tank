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
    recordPointLast = 0;
    //record(10, 0);
    temp = 0;


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

/*
void Player::fillingRecordVector()//заполняем вектор
{
   
        //record.push_back(temp);
        sort(record.begin(), record.end(), std::greater<int>());//сортируем вектор по убыванию
        temp = 0;
        show_vector(record);//выводит вектор на экран
        writingToFile( record);//записываем в файл
       
}
void show_vector(vector<int>& a)//вывод вектора на экран
{
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it;
}

void writingToFile(vector<int>& a)
{
    std::ofstream out;          // поток для записи
    out.open("test.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            out << *it;
        }
    }

    std::cout << "End of program" << std::endl;
}

*/

