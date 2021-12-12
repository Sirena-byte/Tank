#include "Base.h"

Base::Base()
    : life(true) {
    mTexture.loadFromFile("media/baseSprite.png");//загружаем текстуру
    mSprite.setTexture(mTexture);//
    mSprite.setTextureRect(sf::IntRect(0, 0, 48, 48));//загружаем картинку
    mSprite.setPosition(310, 600);//определяем позицию
}
