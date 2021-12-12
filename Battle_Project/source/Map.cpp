#include <Map.h>
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;
/*Map::Map() {
    TileMap = new sf::String[HEIGHT_MAP] 
    {
        "000000000000000000000000000000",
        "00                          00",
        "00                          00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  112211  11  11  00",
        "00  11  11  112211  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00          11  11          00",
        "00          11  11          00",
        "0011  1111          1111  1100",
        "0022  1111          1111  2200",
        "00          11  11          00",
        "00          111111          00",
        "00  11  11  111111  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00  11  11   1111   11  11  00",
        "00           1  1           00",
        "00           1  1           00",
        "000000000000000000000000000000",
    };
    
    
    mTexture.loadFromFile("media/groundSprites.png");
    mTexture.setSmooth(true);
    mSprite.setTexture(mTexture);
}
*/

Map::Map()
{
   
    int level = 1;
    std::ostringstream mData;
    mData << level;
    string str1 = ".txt";//конец строки
    string str2 = "levels/";//начало строки
    string theMyString = (str2 + mData.str() + ".txt");
    ifstream file{ theMyString };
   
    if (!file.is_open()) cout << "ќшибка открыти¤ файла!" << endl;

    TileMap = new sf::String[HEIGHT_MAP];
    vector<string>value;
    string s;

    while (file >> s)
    {
       value.push_back(s);
       cout << s << endl;
    }
    for (int i = 0; i < HEIGHT_MAP; i++)
    {
        cout << value[i] << endl;
        TileMap[i] = value[i];
    }
    file.close();

    mTexture.loadFromFile("media/groundSprites.png");
    mTexture.setSmooth(true);
    mSprite.setTexture(mTexture);
}


void Map::draw(sf::RenderWindow& window) {//функци¤ отрисовки карты
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
            }

            mSprite.setPosition(j * 24, i * 24);//устанавливаем позиции
            window.draw(mSprite);//рисуем карту
        }
}


void Map::break_wall(const int& i, const int& j) {
    TileMap[i][j] = ' ';
}