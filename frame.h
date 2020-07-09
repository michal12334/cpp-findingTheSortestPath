#pragma once

#include <SFML/Graphics.hpp>

class Frame :public sf::Drawable {
public:
	Frame();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setSquareSize(float squareSize);
	float getSquareSize();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Vector2f position;
	float squareSize;
	float frameSize;
	sf::RectangleShape topShape;
	sf::RectangleShape bottomShape;
	sf::RectangleShape leftShape;
	sf::RectangleShape rightShape;
};