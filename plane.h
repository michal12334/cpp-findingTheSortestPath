#pragma once

#include <SFML/Graphics.hpp>
#include "squareWithFrame.h"

class Plane :public sf::Drawable {
public:
	Plane(int squaresNumber, float squareSize, float frameSize);
	void setStartSquare(std::pair<int, int> startSquare);
	void setEndSquare(std::pair<int, int> endSquare);
	void drawOnPlane(sf::RenderWindow *window);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	SquareWithFrame **squares;
	float squareSize;
	int squaresNumber;
	float frameSize;
	std::pair<int, int> startSquare;
	std::pair<int, int> endSquare;
	bool isDrawing;

	void dfs();
	int **distance;
};