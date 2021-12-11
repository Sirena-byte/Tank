#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
class Map;

class Bullet {//класс пули
private:
    float mX, mY, mDx, mDy;//координаты, ускорение
    int mDir;//направление

    sf::Texture mTexture;//текстура

public:
    bool present; //стреляем?
    float timeBeforeShot;//время до выстрела
	sf::Sprite mSprite;

    explicit Bullet(const float &x, const float &y);//непереопределяемая функция пули( параметры: координаты)

	void shoot() { present = true; }//функция стрельбы
    void move(const sf::Int64 &time);
    void update(Map &map, const sf::Int64 &time, float &x, const float &y, const int &dir);//инициализация пули
    void map_interaction(Map &map);//взаимодействие с картой
};
