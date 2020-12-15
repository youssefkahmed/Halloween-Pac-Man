#pragma once
#include "SFML\Graphics.hpp"
#define l 2 
class lose
{
public:
	lose(float width, float height);
	~lose();
	void draw(sf::RenderWindow &window);
	int getPressedNumber(){
		return selectedItemIndex;
	}
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu2[l];
	sf::Texture texture;
	sf::RectangleShape shape;
};