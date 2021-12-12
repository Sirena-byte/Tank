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
    bool gameOver;//êîíåö èãðû
    bool gameStarted;//íà÷àëî
    int level;

    int frags;//ñ÷èòàåò óáèòûõ âðàãîâ
   // int score;
    sf::RenderWindow mWindow;
    sf::Font font;
    sf::Text text;




    Base mBase;
    Map map;
    Player mPlayer;
    Enemy* packOfEnemies;

    //ôóíêöèè âûâîäà ñîîáùåíèé
    Message msgStart;//ñòàðò
    Message msgOver;//êîíåö
    Message msgLost;
    Message msgWon;//ïîáåäà
public:
    Application();

    void process_events();
    void update(const sf::Int64& time);
    void render();
};