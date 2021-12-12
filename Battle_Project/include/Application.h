#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Base.h"
#include "Message.h"
#include<sstream>

class Application : private sf::NonCopyable {
private:
    bool gameOver;//конец игры
    bool gameStarted;//начало
    int level;

    int frags;//считает убитых врагов
   // int score;
    sf::RenderWindow mWindow;
    sf::Font font;
    sf::Text text;
   



    Base mBase;
    Map map;
    Player mPlayer;
    Enemy *packOfEnemies;
 
    //функции вывода сообщений
    Message msgStart;//старт
    Message msgOver;//конец
    Message msgLost;
    Message msgWon;//победа
public:
    Application();

    void process_events();
    void update(const sf::Int64& time);
    void render();
};
