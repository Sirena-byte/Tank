#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Bullet.h"
#include <utility>
class Map;

class Tank : private sf::NonCopyable  {
protected:
    float mX, mY, mWidth, mHeight, mDx, mDy, mSpeed;//координаты ч,у, ширина, высота, ускорение по х, у, скорость
    int mDir;//направление
    float mCurrentFrame;//текущий кадр
    bool mCollision;//столкновение

    sf::String mFile;//файл
    sf::Texture mTexture;//текстура

public:
    explicit Tank(const float &x, const float &y, const float &width, const float &height, const sf::String &file);//явный конструктор(защищает от переопределения типов: int в float и тд)

    bool life;//жизнь

	Bullet bullet;//класс пули
    sf::Sprite mSprite;//спрайт 

    void animate(const sf::Int64 &time);//функция анимации

    void collapse();//функция попадиния
    virtual void move(const sf::Int64 &time) {}//переопределяемая функция движения
    void map_interaction(Map &map);//взаимодействие с картой
    void tank_interaction();//взаимодействие с танком
};
