#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Base.h"
#include "Message.h"

class Application : private sf::NonCopyable {
private:
    bool gameOver;//начало игры
    bool gameStarted;//конец игры

    int frags;

    sf::RenderWindow mWindow;
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
    void update(const sf::Int64 &time);
    void render();
};
