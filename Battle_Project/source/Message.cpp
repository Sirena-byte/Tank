//#include <SFML/System/String.hpp>
#include "Message.h"

Message::Message(const float &x, const float &y, const sf::String &str)
    : mX(x), mY(y) {//инициализируем окно
    
    mFont.loadFromFile("media/PressStart2P.ttf");//загружаем шрифты
    mStr.setFont(mFont);//отправляем шрифт в строку
    mStr.setString(str);//отправляем строку
    mStr.setPosition(mX, mY);//устанавливаем координаты
    mStr.setCharacterSize(25);//установить размер символов
}
