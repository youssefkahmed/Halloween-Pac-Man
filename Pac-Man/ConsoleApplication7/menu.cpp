#include "Menu.h"
#include <iostream>


Menu::Menu(float width, float height)
{
	font.loadFromFile("6809 chargen.ttf");
	texture.loadFromFile("skulls3.JPG");
	
	
	shape.setSize(sf::Vector2f(800.0f, 700.0f));
	shape.setTexture(&texture);
	shape.setPosition(sf::Vector2f(0.0f, 0.0f));

	menu[0].setFont(font);
	menu[0].setString("PLAY----Press Space");
	menu[0].setPosition(sf::Vector2f(width / 4, height / (Max_Number_Items + 1) * 2.3));
	/*menu[0].setColor(sf::Color(58, 133, 154));*/


	menu[1].setFont(font);
	menu[1].setString("Exit----Press Escape");
	menu[1].setPosition(sf::Vector2f(width / 4, height / (Max_Number_Items + 1) * 2.7));
	/*menu[1].setColor(sf::Color(58, 133, 154));*/


	menu[2].setFont(font);
	menu[2].setString("PAC MAN");
	menu[2].setCharacterSize(70);
	menu[2].setPosition(sf::Vector2f(width / 4, height / (Max_Number_Items + 1) * 1.5));
	/*menu[2].setColor(sf::Color(58, 133, 154));*/

	

}




Menu::~Menu(void)
{
}
void Menu::draw(sf::RenderWindow &window)
{
	window.draw(shape);

	for (int i = 0; i <Max_Number_Items; i++)
	{

		window.draw(menu[i]);

	}
	
}