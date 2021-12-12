#include <SFML/Graphics.hpp>
#include "Application.h"
#include<sstream>
#include<iostream>
#include"Info.h"


using namespace std;

Application::Application()
    : mWindow(sf::VideoMode(1000, 672), "Battle City"), gameOver(false), gameStarted(false),//основное окно
    msgStart(90, 330, "Press \'Enter\' to start"), msgOver(250, 300, "Game over"),
    msgLost(260, 350, "You lost"), msgWon(265, 350, "You won"), frags(0){

    sf::Clock clock;

    packOfEnemies = new Enemy[4]{ Enemy(26,31), Enemy(121,391), Enemy(506,391), Enemy(602,31) };

    while (mWindow.isOpen()) {
        sf::Int64 time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        
        process_events();
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            gameStarted = true;

        if (gameStarted && !gameOver)//если начало и не конец
            update(time);
        render();
    }
}


void Application::process_events() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Application::update(const sf::Int64& time) {
   
    for (int i(0); i < 4; ++i)
        if (!packOfEnemies[i].life)//если все враги мертвы
            ++frags;
        else {
            frags = 0;
            break;
        }

    if (frags == 4)
    {
        gameOver = true;//конец игры
        Application::Application();//рестарт игры
    }

    if (!mPlayer.life)//если мертв игрок
    {
        gameOver = true;//конец игры
        Application::Application();//рестарт игры
    }
  
    bool collision;
    for (int i(0); i < 4; ++i) {
        collision = mPlayer.mSprite.getGlobalBounds().intersects(packOfEnemies[i].mSprite.getGlobalBounds());
        if (collision)
            break;
    }
 
    if (mPlayer.life)
        mPlayer.update(time, map, collision);

    for (int i(0); i < 4; ++i) {
        if (packOfEnemies[i].life) {//если есть в наличии враги
            packOfEnemies[i].update(time, map, collision);//инициализируем врага

            if (packOfEnemies[i].bullet.mSprite.getGlobalBounds().intersects(mPlayer.mSprite.getGlobalBounds())
                && packOfEnemies[i].bullet.present) {
                mPlayer.collapse();
                packOfEnemies[i].bullet.present = false;//если пуля врага пересечется с игроком, то пуля мертва
            }

            if (packOfEnemies[i].bullet.mSprite.getGlobalBounds().intersects(mBase.mSprite.getGlobalBounds())
                && packOfEnemies[i].bullet.present) {
                mBase.life = false;//если пуля попадет в штаб, то штаб мертв
                gameOver = true;//игра окончена
            }
            if (mPlayer.bullet.mSprite.getGlobalBounds().intersects(packOfEnemies[i].mSprite.getGlobalBounds())//если пуля игрока попадет во врага
                && mPlayer.bullet.present) {
                packOfEnemies[i].collapse();//минус один враг
                mPlayer.playerScore += 200;//добавляем очки
                cout << mPlayer.playerScore << endl;////////////////////////
                mPlayer.bullet.present = false;//пуля мертва
            }
        }
    }

    if (mPlayer.bullet.mSprite.getGlobalBounds().intersects(mBase.mSprite.getGlobalBounds())//если пуля игрока попадет в штаб
        && mPlayer.bullet.present) {
        mBase.life = false;//база мертва
        gameOver = true;//конец игры
    }
   
}


void Application::render() {//визуализация приложения
    font.loadFromFile("media/PressStart2P.ttf");
    sf::Text text("", font, 20);
    text.setOutlineColor(sf::Color::White);// инициализация текста в инфо колонке


    mWindow.clear();//очистка окна

   

    map.draw(mWindow);//рисуем карту
    if (mPlayer.life)//если игрок жив
    {
        mWindow.draw(mPlayer.mSprite); //рисуем игрока
      
       
    }
    if (mPlayer.bullet.present) mWindow.draw(mPlayer.bullet.mSprite);//если пули есть- рисуем пули
   
    
    for (int i(0); i < 4; ++i) {//цикл от 0 до 4
      
                if (packOfEnemies[i].bullet.present)// если у врагов есть пули
                    mWindow.draw(packOfEnemies[i].bullet.mSprite);//то рисуем пули

                if (packOfEnemies[i].life)//если враг жив
                    mWindow.draw(packOfEnemies[i].mSprite);//рисуем врага
    }
    
    
    
  

    if (mBase.life)//если база жива
        mWindow.draw(mBase.mSprite);//рисуем базу

    if (!gameStarted)
        msgStart.print(mWindow);//окно о запуске игры

    if (gameOver) {//если конец игры
        msgOver.print(mWindow);//тоже какое-то окно
        if (!mBase.life || !mPlayer.life)//если база мертва или мертв игрок

            msgLost.print(mWindow);
        else
            msgWon.print(mWindow);
    }

   
    std::ostringstream info;
    info << mPlayer.playerScore;
    text.setString("score: " + info.str());
    text.setPosition(750, 30);
    mWindow.draw(text);

    mWindow.display();//отрисовка окна
}
