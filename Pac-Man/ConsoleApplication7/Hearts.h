#pragma once

class Heart {
public:
	Heart(sf::Vector2f size) {

		texture.loadFromFile("heart.PNG");
		heart.setTexture(&texture);
		heart.setSize(size);
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(heart);
	}

	sf::FloatRect getGlobalBounds() {
		return heart.getGlobalBounds();
	}//0 . 9 . 19 .10

	void position(sf::Vector2f newPos) {
		heart.setPosition(newPos);
	}
private:
	sf::RectangleShape heart;
	sf::Texture texture;
};