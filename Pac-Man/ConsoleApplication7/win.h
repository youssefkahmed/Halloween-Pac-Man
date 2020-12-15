#pragma once
#include "SFML\Graphics.hpp"
#define s 2 

class win
{
public:
	win(float width, float height);
	~win();
	void draw(sf::RenderWindow &window);
	int getPressedNumber()
	{
		return selectedItemIndex;
	}
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu1[s];
	sf::Texture texture;
	sf::RectangleShape shape;

};