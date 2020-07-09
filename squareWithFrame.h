#pragma once

#include <SFML/Graphics.hpp>
#include "frame.h"

class SquareWithFrame :public sf::Drawable {
public:
	SquareWithFrame();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	Frame frame;
	sf::Vector2f position;
	float size;
	sf::Color squareColor;
	sf::Color frameColor;
	float frameSize;
	sf::RectangleShape shape;
};