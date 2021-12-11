#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Tank.h"

class Player : public Tank {
public:
    Player();

    void move(const sf::Int64 &time);
    void update(const sf::Int64 &time, Map &map, const bool &collision);
};
