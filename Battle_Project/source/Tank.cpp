#include "Tank.h"
#include <Map.h>
#include"Enemy.h"

Tank::Tank(const float &x, const float &y, const float &width, const float &height, const sf::String &file)
    : life(true), mX(x), mY(y), mDx(0.f), mDy(0.f), mFile(file), mDir(0), mCollision(false),
    mCurrentFrame(0.f), mSpeed(0.f), mWidth(width), mHeight(height), 
    bullet(x, y) {//координаты пули

    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(78, 39, mWidth, mHeight));
    mSprite.setPosition(x, y);
}

void Tank::animate(const sf::Int64 &time) {//функци¤ анимации танка
    mCurrentFrame += 0.005f * time;
    if (mCurrentFrame >= 2)//если текущий кадр больше либо равно 2
        mCurrentFrame -= 2;//то возвращаемс¤ в начало

    if (mDx > 0.f)
        mSprite.setTextureRect(sf::IntRect(0 + 39 * (int)mCurrentFrame, 0, 39, 39));//едем вправо
    if (mDx < 0.f)
        mSprite.setTextureRect(sf::IntRect(78 + 39 * (int)mCurrentFrame, 0, 39, 39));//влево
    if (mDy > 0.0f)
        mSprite.setTextureRect(sf::IntRect(0 + 39 * (int)mCurrentFrame, 39, 39, 39));//вверх
    if (mDy < 0.0f)
        mSprite.setTextureRect(sf::IntRect(78 + 39 * (int)mCurrentFrame, 39, 39, 39));//вниз
}

void Tank::collapse() {//в танк попала пул¤

    life = false;//танк мертв
    bullet.present = false;//пул¤ мертва
    mSprite.setPosition(0, 0);//танк в начала
}

void Tank::map_interaction(Map &map) {//взаимодействие с картой
    for (int i = mY / 24; i < (mY + mHeight) / 24; ++i)
        for (int j = mX / 24; j < (mX + mWidth) / 24; ++j) {
            char tile = map.get_tile(i, j);

            if (tile >= '0' && tile <= '@'||tile=='#') {//если символ серый фон или бетон
                if (mDy > 0.f)//если едем вверх
                    mY = i * 24 - mHeight;//не знаю точно что это( наверное, обновление координаты ”)

                if (mDy < 0.f)
                    mY = (float)i * 24 + 24;

                if (mDx > 0.f)
                    mX = j * 24 - mWidth;

                if (mDx < 0.f)
                    mX = (float)j * 24 + 24;
            }
        }

}

void Tank::tank_interaction() {//взаимодействие с танком
    if (mDy > 0.f)
        mY -= 0.3f;

    if (mDy < 0.f)
        mY += 0.3f;

    if (mDx > 0.f)
        mX -= 0.3f;

    if (mDx < 0.f)
        mX += 0.3f;
}
