#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "Tank.h"

class Player : public Tank {
public:
    const int kEnemiesPerLevel = 24;
    const int kEnemiesPerLevelInOneMoment = 6;
    Player();

    void move(const sf::Int64 &time);
    void update(const sf::Int64 &time, Map &map, const bool &collision);
private:
    float m_spawnTimer;//таймер загрузки
    float m_spawnTime;
    int EnemySpawnerSpawnTime=5;
};
