#include <Bullet.h>
#include <Map.h>

Bullet::Bullet(const float &x, const float &y)
    : present(false), mX(x), mY(y), mDir(0), mDx(0.f), mDy(0.f), timeBeforeShot(0.f) {

    mTexture.loadFromFile("media/bulletSprite.png");//загружаем текстуру
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, 9, 12));//получаем картинку
    mSprite.setPosition(x, y);//устанавливаем позицию
}

void Bullet::move(const sf::Int64 &time) {//функция движения пули
    switch (mDir) {//направление
        case 0:
            mDx = 0.15f;//вправо
            mDy = 0;
			mSprite.setRotation(90.f);//спрайт поворачиваем на 90 градусов
            break;

        case 1:
            mDx = -0.15f;//влево
            mDy = 0;
			mSprite.setRotation(-90.f);
            break;

        case 2:
            mDx = 0;
            mDy = 0.15f;//вверх
			mSprite.setRotation(180.f);
            break;

        case 3:
            mDx = 0;
            mDy = -0.15f;//вниз
			mSprite.setRotation(0.f);
            break;
    }

    mX += mDx * time;// задаем движение по иксу
    mY += mDy * time;// то же по игрику
	mSprite.setPosition(mX, mY);//устанавливаем позицию
}

void Bullet::update(Map &map, const sf::Int64 &time, float &x, const float &y, const int &dir) {//инициализация пули
    if (present) {
        move(time);//если пуля движется
        map_interaction(map);//взаимодействует с картой
    }
    else {
		mDir = dir;//определяем направление
        switch (mDir) {
        case 0:
            mX = x + 35.f;
            mY = y + 15.f;
            break;

        case 1:
            mX = x + 7.f;
            mY = y + 23.f;
            break;

        case 2:
            mX = x + 23.f;
            mY = y + 32.f;
            break;

        case 3:
            mX = x + 15.f;
            mY = y + 5.f;
            break;
        }
		mSprite.setPosition(mX, mY);//задаем позицию
    }
}

void Bullet::map_interaction(Map &map) {//взаимодействие с картой
    for (int i = mY / 24; i < (mY + 12) / 24; ++i)
        for (int j = mX / 24; j < (mX + 9) / 24; ++j) {//проходим все тайлы
            char tile = map.get_tile(i, j);//получить символ тайла

            if (tile == '0' || tile == '@')//если серый фон или бетон
                present = false;//ничего не происходит

            if (tile == '#') {//если кирпич
                map.break_wall(i, j);//сломать стену
                present = false;// тайла нет
            }
        }
}
