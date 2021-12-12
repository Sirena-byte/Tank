#include"Info.h"


Info::Info(const float& x, const float& y, const sf::String& str, int size, int num)
{

    mX = x; mY = y;
    mData << num;
    mFont.loadFromFile("media/PressStart2P.ttf");//загружаем шрифты
    mStr.setFont(mFont);//отправляем шрифт в строку
    mStr.setString(str + mData.str());//отправляем строку
    mStr.setPosition(mX, mY);//устанавливаем координаты
    mStr.setCharacterSize(15);//установить размер символов
    mData << num;
}

