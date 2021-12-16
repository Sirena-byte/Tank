#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<sstream>
#include"Player.h"
class Message {
private:
    float mX, mY;//координаты окна
    std::ostringstream mData, mData1;
    sf::Font mFont;//класс шрифта
    sf::Text mStr;//текстовая строка
    
public:
    Message(const float& x, const float& y, const sf::String& str);//инициализация вывода сообщения 


  
   void msg(const float& x, const float& y, const sf::String& str);
   void info(const float& x, const float& y, const sf::String& str, int size, int num);
   void info2(const float& x, const float& y, int pos, const sf::String& str2, int size, int num);
   void print(sf::RenderWindow& window) 
   {
       window.draw(mStr); 
   }//функция печати
 
};
