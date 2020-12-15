#pragma once

class Coin {
public:
    Coin(sf::Vector2f size) {
		
		texture.loadFromFile("diamond.PNG");
		coin.setTexture(&texture);
        coin.setSize(size);
       
    }
 
    void drawTo(sf::RenderWindow &window) {
        window.draw(coin);
    }
 
    sf::FloatRect getGlobalBounds() {
        return coin.getGlobalBounds();
    }
 
    void position(sf::Vector2f newPos) {
        coin.setPosition(newPos);
    }
private:
    sf::RectangleShape coin;
	sf::Texture texture ;
};