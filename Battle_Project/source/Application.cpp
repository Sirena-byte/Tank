#include <SFML/Graphics.hpp>
#include "Application.h"
#include<sstream>
#include<iostream>
#include"bonus.h"
#include"menu.h"
#include<Info.h>

using namespace std;
int temp;//временная переменная
Application::Application()
    : mWindow(sf::VideoMode(1000, 672), "Battle City"), gameOver(false), gameStarted(false),
    /* msgStart(90, 330, "Press \'Enter\' to start"), msgOver(250, 300, "Game over"),
     msgLost(260, 350, "You lost"), msgWon(),*/
    frags(0)
{
    //playerScore = 0;
   
  
    read();//..........................................................................считали файл
    menu(mWindow);//вызов меню
    initialize();
    
}
void Application::initialize()
{
    sf::Clock clock;
    packOfEnemies = new Enemy[4]{ Enemy(26,31), Enemy(121,391), Enemy(506,391), Enemy(602,31) };//инициализируем врагов

    while (mWindow.isOpen()) {
        sf::Int64 time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
  
        process_events();
        

       // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))// старт при нажатии ентер
           gameStarted = true;
        

        if (gameStarted && !gameOver)
            update(time);
       
        render();
    }
}

void Application::process_events()
{
    sf::Event event;

    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Application::update(const sf::Int64& time)
{
    
    for (int i(0); i < 4; ++i)
        if (!packOfEnemies[i].life)
            ++frags;//если враг убит, то флаг++
        else
        {
            frags = 0;
            break;
        }

    if (frags == 4)
    {
        //gameOver = true;
     
        map.levelMap();
        initialize();
    }

    if (!mPlayer.life)//если игрок мертв, то конец игры
    {
        recordStatistics(temp);//сравниваем очки и записываем в файл
        gameOver = true;
       

        //gameOver = false; gameStarted = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))// старт при нажатии ентер
        {
            gameStarted = true;
            initialize();

        }
    }

    bool collision;
    for (int i(0); i < 4; ++i)
    {
        collision = mPlayer.mSprite.getGlobalBounds().intersects(packOfEnemies[i].mSprite.getGlobalBounds());
        if (collision)
            break;
    }

    if (mPlayer.life)
        mPlayer.update(time, map, collision);

    for (int i(0); i < 4; ++i)
    {
        if (packOfEnemies[i].life)
        {
            packOfEnemies[i].update(time, map, collision);

            if (packOfEnemies[i].bullet.mSprite.getGlobalBounds().intersects(mPlayer.mSprite.getGlobalBounds())
                && packOfEnemies[i].bullet.present)
            {
                mPlayer.collapse();
                packOfEnemies[i].bullet.present = false;
            }

            if (packOfEnemies[i].bullet.mSprite.getGlobalBounds().intersects(mBase.mSprite.getGlobalBounds())
                && packOfEnemies[i].bullet.present)
            {
                recordStatistics(temp);
                mBase.life = false;//база мертва
                gameOver = true;//конец игры

            }
            if (mPlayer.bullet.mSprite.getGlobalBounds().intersects(packOfEnemies[i].mSprite.getGlobalBounds())
                && mPlayer.bullet.present)
            {
                packOfEnemies[i].collapse();
                mPlayer.playerScore += 200;


               
               
              if (mPlayer.playerScore != 0)
               {
                   temp = mPlayer.playerScore;//копируем очки во врекменную переменную
             
               }
              
               
          
                mPlayer.bullet.present = false;
            }
        }
    }

    if (mPlayer.bullet.mSprite.getGlobalBounds().intersects(mBase.mSprite.getGlobalBounds())
        && mPlayer.bullet.present)
    {
        recordStatistics(temp);
       mBase.life = false;
        gameOver = true;
    }

}




void Application::render() //отрисовка
{
    //.....................................................................................................
    font.loadFromFile("media/PressStart2P.ttf");
    sf::Text text("", font, 20);
    text.setOutlineColor(sf::Color::White);
    std::ostringstream info;
    //............................................................................................................

   
//...................................................................................................

    mWindow.clear();

    map.draw(mWindow);//рисуем карту

    if (mPlayer.life)//если игрок жив- рисуем игрока
    {
        mWindow.draw(mPlayer.mSprite);
       // mBonus.TimerBonus();//появление бонусов...............................................................
       
    }

    if (mPlayer.bullet.present)//рисуем пули
    {
        mWindow.draw(mPlayer.bullet.mSprite);
    }


    for (int i(0); i < 4; ++i) //рисуем врагов
    {

        if (packOfEnemies[i].bullet.present)
            mWindow.draw(packOfEnemies[i].bullet.mSprite);

        if (packOfEnemies[i].life)
            mWindow.draw(packOfEnemies[i].mSprite);
    }

    if (mBase.life)//рисуем базу
    {
        mWindow.draw(mBase.mSprite);
    }

    if (!gameStarted)
    {/*
        text.setString("Press \'Enter\' to start");
        text.setPosition(90, 330);
        mWindow.draw(text);
        */
    }

    if (gameOver)
    {
        text.setString("Game over");
        text.setPosition(250, 300);
        mWindow.draw(text);

        if (!mBase.life || !mPlayer.life)
        {

            text.setString("You lost");
            text.setPosition(260, 350);
            mWindow.draw(text);
        }
        else
        {
            text.setString("You won");
            text.setPosition(265, 350);
            mWindow.draw(text);
        }
    }
    //.................................................................................................................................

    info <<mPlayer.playerScore;
    text.setString("score: " + info.str());//выводим очки игрока
    text.setPosition(750, 30);
    mWindow.draw(text);
//............................................................................................................................
   
    
    
    
    
    
    
    
    mWindow.display();
}
