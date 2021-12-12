#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map : private sf::NonCopyable {
private:
    static const int HEIGHT_MAP = 28;
    static const int WIDTH_MAP = 30;

    sf::String *TileMap;
    //vector<string>TileMap;
   
    sf::Texture mTexture;
    sf::Sprite mSprite;
 
    
    

public:
    Map();

    void break_wall(const int &i, const int &j);//ломать стену
    const char get_tile(const int &i, const int &j) { return TileMap[i][j]; }// функция получения тайла
    void draw(sf::RenderWindow &window);//рисует окно
   
};
