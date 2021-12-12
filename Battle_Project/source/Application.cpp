#include <SFML/Graphics.hpp>
#include "Application.h"
#include<sstream>
#include<iostream>
#include"Info.h"


using namespace std;

Application::Application()
    : mWindow(sf::VideoMode(1000, 672), "Battle City"), gameOver(false), gameStarted(false),//îñíîâíîå îêíî
    msgStart(90, 330, "Press \'Enter\' to start"), msgOver(250, 300, "Game over"),
    msgLost(260, 350, "You lost"), msgWon(265, 350, "You won"), frags(0) {

    sf::Clock clock;

    packOfEnemies = new Enemy[4]{ Enemy(26,31), Enemy(121,391), Enemy(506,391), Enemy(602,31) };

    while (mWindow.isOpen()) {
        sf::Int64 time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        process_events();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            gameStarted = true;

        if (gameStarted && !gameOver)//åñëè íà÷àëî è íå êîíåö
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
        if (!packOfEnemies[i].life)//åñëè âñå âðàãè ìåðòâû
            ++frags;
        else {
            frags = 0;
            break;
        }

    if (frags == 4)
    {
        gameOver = true;//êîíåö èãðû
        Application::Application();//ðåñòàðò èãðû
    }

    if (!mPlayer.life)//åñëè ìåðòâ èãðîê
    {
        gameOver = true;//êîíåö èãðû
        Application::Application();//ðåñòàðò èãðû
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
        if (packOfEnemies[i].life) {//åñëè åñòü â íàëè÷èè âðàãè
            packOfEnemies[i].update(time, map, collision);//èíèöèàëèçèðóåì âðàãà

            if (packOfEnemies[i].bullet.mSprite.getGlobalBounds().intersects(mPlayer.mSprite.getGlobalBounds())
                && packOfEnemies[i].bullet.present) {
                mPlayer.collapse();
                packOfEnemies[i].bullet.present = false;//åñëè ïóëÿ âðàãà ïåðåñå÷åòñÿ ñ èãðîêîì, òî ïóëÿ ìåðòâà
            }

            if (packOfEnemies[i].bullet.mSprite.getGlobalBounds().intersects(mBase.mSprite.getGlobalBounds())
                && packOfEnemies[i].bullet.present) {
                mBase.life = false;//åñëè ïóëÿ ïîïàäåò â øòàá, òî øòàá ìåðòâ
                gameOver = true;//èãðà îêîí÷åíà
            }
            if (mPlayer.bullet.mSprite.getGlobalBounds().intersects(packOfEnemies[i].mSprite.getGlobalBounds())//åñëè ïóëÿ èãðîêà ïîïàäåò âî âðàãà
                && mPlayer.bullet.present) {
                packOfEnemies[i].collapse();//ìèíóñ îäèí âðàã
                mPlayer.playerScore += 200;//äîáàâëÿåì î÷êè
                cout << mPlayer.playerScore << endl;////////////////////////
                mPlayer.bullet.present = false;//ïóëÿ ìåðòâà
            }
        }
    }

    if (mPlayer.bullet.mSprite.getGlobalBounds().intersects(mBase.mSprite.getGlobalBounds())//åñëè ïóëÿ èãðîêà ïîïàäåò â øòàá
        && mPlayer.bullet.present) {
        mBase.life = false;//áàçà ìåðòâà
        gameOver = true;//êîíåö èãðû
    }

}


void Application::render() {//âèçóàëèçàöèÿ ïðèëîæåíèÿ
    font.loadFromFile("media/PressStart2P.ttf");
    sf::Text text("", font, 20);
    text.setOutlineColor(sf::Color::White);// èíèöèàëèçàöèÿ òåêñòà â èíôî êîëîíêå


    mWindow.clear();//î÷èñòêà îêíà



    map.draw(mWindow);//ðèñóåì êàðòó
    if (mPlayer.life)//åñëè èãðîê æèâ
    {
        mWindow.draw(mPlayer.mSprite); //ðèñóåì èãðîêà


    }
    if (mPlayer.bullet.present) mWindow.draw(mPlayer.bullet.mSprite);//åñëè ïóëè åñòü- ðèñóåì ïóëè


    for (int i(0); i < 4; ++i) {//öèêë îò 0 äî 4

        if (packOfEnemies[i].bullet.present)// åñëè ó âðàãîâ åñòü ïóëè
            mWindow.draw(packOfEnemies[i].bullet.mSprite);//òî ðèñóåì ïóëè

        if (packOfEnemies[i].life)//åñëè âðàã æèâ
            mWindow.draw(packOfEnemies[i].mSprite);//ðèñóåì âðàãà
    }





    if (mBase.life)//åñëè áàçà æèâà
        mWindow.draw(mBase.mSprite);//ðèñóåì áàçó

    if (!gameStarted)
        msgStart.print(mWindow);//îêíî î çàïóñêå èãðû

    if (gameOver) {//åñëè êîíåö èãðû
        msgOver.print(mWindow);//òîæå êàêîå-òî îêíî
        if (!mBase.life || !mPlayer.life)//åñëè áàçà ìåðòâà èëè ìåðòâ èãðîê

            msgLost.print(mWindow);
        else
            msgWon.print(mWindow);
    }


    std::ostringstream info;
    info << mPlayer.playerScore;
    text.setString("score: " + info.str());
    text.setPosition(750, 30);
    mWindow.draw(text);

    mWindow.display();//îòðèñîâêà îêíà
}
