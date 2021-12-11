#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Message {
private:
    float mX, mY;//координаты окна

    sf::Font mFont;//класс шрифта
    sf::Text mStr;//текстовая строка

public:
    explicit Message(const float &x, const float &y, const sf::String &str);//инициализация вывода сообщения 

    void print(sf::RenderWindow &window) { window.draw(mStr); }//функция печати
};
