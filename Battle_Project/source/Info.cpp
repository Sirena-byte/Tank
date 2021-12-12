#include"Info.h"


Info::Info(const float& x, const float& y, const sf::String& str, int size, int num)
{

    mX = x; mY = y;
    mData << num;
    mFont.loadFromFile("media/PressStart2P.ttf");//��������� ������
    mStr.setFont(mFont);//���������� ����� � ������
    mStr.setString(str + mData.str());//���������� ������
    mStr.setPosition(mX, mY);//������������� ����������
    mStr.setCharacterSize(15);//���������� ������ ��������
    mData << num;
}

