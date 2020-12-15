#include "win.h"
#include <iostream>		


win::win(float width, float height)
{
	font.loadFromFile("arial1.ttf");
	texture.loadFromFile("hallo.PNG");



	menu1[0].setFont(font);
	menu1[0].setString("You Win");
	menu1[0].setCharacterSize(50);
	menu1[0].setPosition(sf::Vector2f(width / 3, height / 3));

	menu1[1].setFont(font);
	menu1[1].setString("your Score is :- 56");
	menu1[1].setPosition(sf::Vector2f(width / 3, height / 2));
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(100.f, 100.f));
	shape.setPosition(sf::Vector2f(40, 400));


	selectedItemIndex = 0;

}


win::~win()
{
}
void win::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < s; i++)
	{
		window.draw(menu1[i]);
	}
	window.draw(shape);
}