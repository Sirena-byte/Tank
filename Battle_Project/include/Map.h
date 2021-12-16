#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
//#include"Application.h"

#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include"Player.h"
class Map : private sf::NonCopyable {
private:
    

    sf::String* TileMap;
    

    sf::Texture mTexture;
    sf::Sprite mSprite;
    Player mPlayer;


public:

    Map();
    static const int HEIGHT_MAP = 28;
    static const int WIDTH_MAP = 30;
    int level;
    void levelMap();
    void break_wall(const int& i, const int& j);//ломать стену
    const char get_tile(const int& i, const int& j) { return TileMap[i][j]; }// функция получения тайла
    void draw(sf::RenderWindow& window);//рисует 
   // void getMap();
};