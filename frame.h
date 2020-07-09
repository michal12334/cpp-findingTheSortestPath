#pragma once

#include <SFML/Graphics.hpp>

class Frame :public sf::Drawable {
public:
	Frame();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Vector2f position;
	sf::Vector2f squareSize;
	sf::Vector2f frameSize;
	sf::RectangleShape topShape;
	sf::RectangleShape bottomShape;
	sf::RectangleShape leftShape;
	sf::RectangleShape rightShape;
};