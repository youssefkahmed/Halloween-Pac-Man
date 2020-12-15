#pragma once
#include "SFML\Graphics.hpp"

#define Max_Number_Items 3
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	

private:
	sf::Font font;
	sf::Text menu[Max_Number_Items];
	sf::Texture texture;
	sf::RectangleShape shape;


};