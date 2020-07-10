#pragma once

#include <SFML/Graphics.hpp>
#include "squareWithFrame.h"
#include <queue>

class Plane :public sf::Drawable {
public:
	Plane(int squaresNumber, float squareSize, float frameSize);
	void setStartSquare(std::pair<int, int> startSquare);
	void setEndSquare(std::pair<int, int> endSquare);
	void drawOnPlane(sf::RenderWindow *window);
	void bfs();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	SquareWithFrame **squares;
	float squareSize;
	int squaresNumber;
	float frameSize;
	std::pair<int, int> startSquare;
	std::pair<int, int> endSquare;
	bool isDrawing;

	void bfsHelp();
	int **distance;
	bool isDfsAvaliable;
	std::queue< std::pair<int, int> > q;
	std::pair<int, int> point;
	std::pair<int, int> temp;
};