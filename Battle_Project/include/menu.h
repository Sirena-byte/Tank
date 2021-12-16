#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;


void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, constructionTexture, menuBackground;
	menuTexture1.loadFromFile("media/start_menu3.png");
	menuTexture2.loadFromFile("media/construction_menu.png");
	menuTexture3.loadFromFile("media/exit_menu.png");
	constructionTexture.loadFromFile("media/Penguins.jpg");
	menuBackground.loadFromFile("media/start3_3.png");//фоновая картинка меню
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),construction(constructionTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	//позиция
	menu1.setPosition(419, 300);
	menu2.setPosition(280, 400);
	menu3.setPosition(429, 500);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(0,0,0));//фоновый цвет

		if (IntRect(419, 300, 162, 47).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; }//первые 2 параметра расположение области нажатия по х,у. вторые 2 параметра -размер области нажатия
		if (IntRect(280, 400, 439, 72).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
		if (IntRect(429, 500, 143, 72).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(construction); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
}