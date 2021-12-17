#include <Map.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include"bonus.h"


using namespace std;


Map::Map()
{

    level = 1;
    std::ostringstream mData;
    mData << level;
    string str1 = ".txt";//конец строки
    string str2 = "levels/";//начало строки
    string theMyString = (str2 + mData.str() + ".txt");
    ifstream file{ theMyString };

    if (!file.is_open()) cout << "ошибка открытия файла!" << endl;

    TileMap = new sf::String[HEIGHT_MAP];
   
    vector<string> value;//вектор куда счивывается карта из файла
    string s;

    while (file >> s)
    {
        value.push_back(s);
       // cout << s << endl;
    }
    for (int i = 0; i < HEIGHT_MAP; i++)
    {
       
        TileMap[i] = value[i];//и сохраняется 
       // cout << value[i] << endl;
    }
    
    

    mTexture.loadFromFile("media/groundSprites.png");
    mTexture.setSmooth(true);
    mSprite.setTexture(mTexture);
    level++;
}
void Map::levelMap()
{

    std::ostringstream mData;
    mData << level;
    string str1 = ".txt";//конец строки
    string str2 = "levels/";//начало строки
    string theMyString = (str2 + mData.str() + ".txt");
    ifstream file{ theMyString };

    if (!file.is_open()) cout << "ошибка открытия файла!" << endl;

    TileMap = new sf::String[HEIGHT_MAP];
    vector<string>value;
    string s;

    while (file >> s)
    {
        value.push_back(s);
        //cout << s << endl;
    }
    for (int i = 0; i < HEIGHT_MAP; i++)
    {
       // cout << value[i] << endl;
        TileMap[i] = value[i];
    }
    
    file.close();
    system("cls");
   

    mTexture.loadFromFile("media/groundSprites.png");
    mTexture.setSmooth(true);
    mSprite.setTexture(mTexture);
   level++;
   if (level >3)
   {
       level = 1;
   }
}

void Map::draw(sf::RenderWindow& window) {//функция отрисовки карты
    for (int i(0); i < HEIGHT_MAP; i++)
        for (int j(0); j < WIDTH_MAP; j++) {//проходим по всей карте
            switch (TileMap[i][j]) {
            case '.':
                mSprite.setTextureRect(sf::IntRect(0, 0, 24, 24));//рисуем тайлы
                break;

            case '0':
                mSprite.setTextureRect(sf::IntRect(72, 0, 24, 24));
                break;

            case '#':
                mSprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
                break;

            case '@':
                mSprite.setTextureRect(sf::IntRect(48, 0, 24, 24));
                break;

            case'1':
                mSprite.setTextureRect(sf::IntRect(96,0,24,24));
                mSprite.setScale(2, 2);
                break;

            case'2':
                mSprite.setTextureRect(sf::IntRect(120,0,24,24));
                mSprite.setScale(2, 2);
                break;
            case '3':
                mSprite.setTextureRect(sf::IntRect(144,0,24,24));
                mSprite.setScale(2, 2);
                break;
            }
            mSprite.setPosition(j * 24, i * 24);//устанавливаем позиции
            window.draw(mSprite);//рисуем карту
        }
}


void Map::break_wall(const int& i, const int& j) {
    TileMap[i][j] = '.';
}


void Map::randomBonusCreate()
  {
    int randomElemrntX = 0;
    int randomElementY = 0;

    srand(time(0));
    int countBonus = 5;

    
        randomElemrntX = 1 + rand() % (WIDTH_MAP - 1);
        randomElementY = 1 + rand() % (HEIGHT_MAP - 1);
        int tmp;

        if (TileMap[randomElemrntX][randomElementY] == '.' || TileMap[randomElemrntX][randomElementY] == '#')
        {
           /*TileMap[randomElemrntX][randomElementY]*/ tmp = rand() % 3;//рандомно выбирается тайл бонуса
           if (/*TileMap[randomElemrntX][randomElementY]*/tmp == 0) { TileMap[randomElemrntX][randomElementY] = '1'; }
           if (/*TileMap[randomElemrntX][randomElementY]*/tmp == 1) { TileMap[randomElemrntX][randomElementY] = '2'; }
           if (/*TileMap[randomElemrntX][randomElementY]*/tmp == 2) { TileMap[randomElemrntX][randomElementY] = '3'; }

           cout << "koordinate X= " << randomElemrntX << "\tkoordinate Y= " << randomElementY << endl;
        }
    
}