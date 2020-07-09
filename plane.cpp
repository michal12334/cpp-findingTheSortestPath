#include "plane.h"

using namespace sf;
using namespace std;

Plane::Plane(int squaresNumber, float squareSize, float frameSize) {
	this->squaresNumber = squaresNumber;
	this->squareSize = squareSize;
	this->frameSize = frameSize;

	squares = new SquareWithFrame * [squaresNumber];
	for(int i = 0; i < squaresNumber; i++) {
		squares[i] = new SquareWithFrame [squaresNumber];

		for(int j = 0; j < squaresNumber; j++) {
			squares[i][j].setSquareSize(squareSize);
			squares[i][j].setFrameSize(frameSize);
			squares[i][j].setPosition(Vector2f{i * squareSize, j * squareSize});
		}
	}
}

void Plane::setStartSquare(pair<int, int> startSquare) {
	this->startSquare = startSquare;
}

void Plane::setEndSquare(pair<int, int> endSquare) {
	this->endSquare = endSquare;
}

void Plane::draw(RenderTarget &target, RenderStates state) const {
	for(int i = 0; i < this->squaresNumber; i++) {
		for(int j = 0; j < this->squaresNumber; j++) {
			target.draw(this->squares[i][j], state);
		}
	}
}