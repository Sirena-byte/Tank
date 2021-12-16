#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Base.h"
#include "Message.h"
#include<sstream>
#include"bonus.h"
#include<vector>

using namespace std;

class Application : private sf::NonCopyable {
private:
    bool gameOver;
    bool gameStarted;
  

    int frags;
   // int score;
    sf::RenderWindow mWindow;
    sf::Font font;
    sf::Font font1, font2, font3, font4, font5, font6, font7, font8, font9, font10;
    sf::Text text;
    sf::Text text2, text3, text4, text5, text6, text7, text8, text9, text10;

    Base mBase;
    Map map;
    Player mPlayer;
    Enemy* packOfEnemies;
    Bonus mBonus;

public:
   //vector<int>record;//вектор для хранения рекордов
    //int playerScore;//текущие очки


    Application();
   
    void initialize();
    void process_events();
    void update(const sf::Int64& time);
    void render();
   // void sort();
};