#include "lose.h"


lose::lose(float width, float height)
{
	font.loadFromFile("arial1.ttf");
	texture.loadFromFile("hallo.PNG");



	menu2[0].setFont(font);
	menu2[0].setString("Game over");
	menu2[0].setCharacterSize(50);
	menu2[0].setPosition(sf::Vector2f(width / 3, height / 3));


	menu2[1].setFont(font);
	menu2[1].setString("you are loser ");
	menu2[1].setPosition(sf::Vector2f(width / 3, height / 2));

	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(100.f, 100.f));
	shape.setPosition(sf::Vector2f(40, 400));


	selectedItemIndex = 0;
}


lose::~lose()
{
}
void lose::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < l; i++)
	{
		window.draw(menu2[i]);
	}
	
	window.draw(shape);
}