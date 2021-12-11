#include <SFML/Window/Keyboard.hpp>
#include "Player.h"
#include <Map.h>
#include"Application.h"
#include<iostream>
using sf::Keyboard;
using namespace std;


Player::Player()
    : Tank(244, 600, 39, 39, "media/playerSprites.png") {//������������� ������

}

void Player::move(const sf::Int64& time) {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        mDir = 1;
        mSpeed = 0.11f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        mDir = 0;
        mSpeed = 0.11f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        mDir = 3;
        mSpeed = 0.11f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        mDir = 2;
        mSpeed = 0.11f;
    }

    switch (mDir) {
    case 0:
        mDx = mSpeed;//����������� ������
        mDy = 0;
        break;

    case 1:
        mDx = -mSpeed;//�����
        mDy = 0;
        break;

    case 2:
        mDx = 0;
        mDy = mSpeed;//�����;
            break;

    case 3:
        mDx = 0;
        mDy = -mSpeed;//����
        break;
    }
    if (mCollision) tank_interaction();//���� ������������ � ������
    mX += mDx * time;
    mY += mDy * time;
}

void Player::update(const sf::Int64& time, Map& map, const bool& collision) {
    mCollision = collision;
    move(time);

    mSpeed = 0.f;//��������
    mSprite.setPosition(mX, mY);//��������� �������
    animate(time);//��������
    map_interaction(map);//�������������� � ������

    bullet.update(map, time, mX, mY, mDir);//������������� ����
    if (!bullet.present)//���� �� ��������
        if (Keyboard::isKeyPressed(Keyboard::Space)) {//���� ����� ������
            bullet.timeBeforeShot += time;
            if (bullet.timeBeforeShot > 10.f) {//�������� ����� ������
                bullet.present = true;//��������
                bullet.timeBeforeShot = 0.f;//������������))
            }
        }
}
