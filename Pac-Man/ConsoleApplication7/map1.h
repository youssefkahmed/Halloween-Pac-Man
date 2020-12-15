#pragma once

class Map1 {
public:
    Map1 (sf::Vector2f size) {
		
		texture.loadFromFile("map3.png");
		mapS.setTexture(&texture);
        mapS.setSize(size);
       
    }
 
    void drawMap(sf::RenderWindow &window) {
        window.draw(mapS);
    }
 
    sf::FloatRect getGlobalBounds() {
		return mapS.getGlobalBounds();
    }
 
    void position(sf::Vector2f newPos) {
        mapS.setPosition(newPos);
    }
private:
    sf::RectangleShape mapS;
	sf::Texture texture ;
};