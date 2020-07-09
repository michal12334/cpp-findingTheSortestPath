#pragma once

#include <SFML/Graphics.hpp>
#include "squareWithFrame.h"

class Plane :public sf::Drawable {
public:
	Plane(int squaresNumber, float squareSize, float frameSize);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	SquareWithFrame **squares;
	float squareSize;
	int squaresNumber;
	float frameSize;
};