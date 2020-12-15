#include "Difficulty.h"
#include <iostream>


Difficulty::Difficulty(float width, float height)
{
	int display_diff_menu = 0;

	font.loadFromFile("6809 chargen.ttf");
	texture.loadFromFile("skulls3.JPG");
	
	
	shape2.setSize(sf::Vector2f(800.0f, 700.0f));
	shape2.setTexture(&texture);
	shape2.setPosition(sf::Vector2f(0.0f, 0.0f));

	difficulty[0].setFont(font);
	difficulty[0].setString("EASY----Press E");
	difficulty[0].setPosition(sf::Vector2f(width / 4, height / (Max_Number_Item + 1) * 2.3));
	/*difficulty[0].setColor(sf::Color(58, 133, 154));*/


	difficulty[1].setFont(font);
	difficulty[1].setString("MEDIUM----Press M");
	difficulty[1].setPosition(sf::Vector2f(width / 4, height / (Max_Number_Item + 1) * 2.7));
	/*difficulty[1].setColor(sf::Color(58, 133, 154));*/


	difficulty[2].setFont(font);
	difficulty[2].setString("DIFFICULTY");
	difficulty[2].setCharacterSize(70);
	difficulty[2].setPosition(sf::Vector2f(width / 4, height / (Max_Number_Item + 1) * 1.5));
	/*difficulty[2].setColor(sf::Color(58, 133, 154));*/

	
	
	selectedItemIndex = 0;
}



Difficulty::~Difficulty(void)
{
}

void Difficulty::draw(sf::RenderWindow &window)
{   
	

	window.draw(shape2);

	for (int i = 0; i <3; i++)
	{

		window.draw(difficulty[i]);

	
	}
}
