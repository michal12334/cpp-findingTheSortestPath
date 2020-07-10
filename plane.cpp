#include "plane.h"

using namespace sf;
using namespace std;

Plane::Plane(int squaresNumber, float squareSize, float frameSize) {
	this->squaresNumber = squaresNumber;
	this->squareSize = squareSize;
	this->frameSize = frameSize;
	this->isDrawing = true;

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

void Plane::drawOnPlane(RenderWindow *window) {
	if(!this->isDrawing)
		return;

	if(Mouse::isButtonPressed(Mouse::Button::Left)) {
		for(int i = 0; i < this->squaresNumber; i++) {
			for(int j = 0; j < this->squaresNumber; j++) {
				if(make_pair(i, j) != startSquare && make_pair(i, j) != endSquare) {
					if(squares[i][j].isMouseInside(window)) {
						squares[i][j].setSquareColor(Color::Yellow);
					}
				}
			}
		}
	}

	if(Keyboard::isKeyPressed(Keyboard::Key::Space))
		this->isDrawing = false;
}

void Plane::draw(RenderTarget &target, RenderStates state) const {
	for(int i = 0; i < this->squaresNumber; i++) {
		for(int j = 0; j < this->squaresNumber; j++) {
			target.draw(this->squares[i][j], state);
		}
	}
}