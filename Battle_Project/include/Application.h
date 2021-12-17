#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Base.h"
#include "Message.h"
#include<sstream>
//#include"bonus.h"
#include<vector>

using namespace std;

class Application : private sf::NonCopyable {
private:
    bool gameOver;
    bool gameStarted;
    int createObjectForMapTimer;

    int frags;
   // int score;
    sf::RenderWindow mWindow;
    sf::Font font;
    sf::Text text;

    Base mBase;
    Map map;
    Player mPlayer;
    Enemy* packOfEnemies;
    //Bonus mBonus;

  

public:
 
    Application();
   
    void initialize();
    void process_events();
    void update(const sf::Int64& time);
    void render();
 
};