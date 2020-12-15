#pragma once
#include "SFML\Graphics.hpp"

#define Max_Number_Item 4
class Difficulty
{
public:
	Difficulty(float width, float height);
	~Difficulty();

	void draw(sf::RenderWindow &window);
	int getPressedNumber(){
		return selectedItemIndex;
	}

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text difficulty[Max_Number_Item];
	sf::Texture texture;
	sf::RectangleShape shape2;


};

