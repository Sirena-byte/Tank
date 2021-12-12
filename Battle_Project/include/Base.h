#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Base : private sf::NonCopyable {
private:
    sf::Texture mTexture;//текстура

public:
    sf::Sprite mSprite;//спрайт
    bool life;//жизнь

    Base();
};
