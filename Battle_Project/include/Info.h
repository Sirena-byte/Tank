#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<sstream>
#include"Player.h"
class Info {
private:
    float mX, mY;//координаты окна
    std::ostringstream mData;
    sf::Font mFont;//класс шрифта
    sf::Text mStr;//текстовая строка

public:
    Info(const float& x, const float& y, const sf::String& str, int size, int num);//инициализация вывода сообщения 
};