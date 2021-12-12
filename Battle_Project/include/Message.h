#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<sstream>
#include"Player.h"
class Message {
private:
    float mX, mY;//���������� ����
    std::ostringstream mData;
    sf::Font mFont;//����� ������
    sf::Text mStr;//��������� ������
    
public:
    Message(const float& x, const float& y, const sf::String& str);//������������� ������ ��������� 
    Message();
   void info(const float& x, const float& y, const sf::String& str, int size, int num);
   void print(sf::RenderWindow& window) 
   {
       window.draw(mStr); 
   }//������� ������
 
};
