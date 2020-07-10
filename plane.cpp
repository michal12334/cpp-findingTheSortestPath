#include "plane.h"
#include <queue>

using namespace sf;
using namespace std;

Plane::Plane(int squaresNumber, float squareSize, float frameSize) {
	this->squaresNumber = squaresNumber;
	this->squareSize = squareSize;
	this->frameSize = frameSize;
	this->isDrawing = true;
	this->isDfsAvaliable = true;

	squares = new SquareWithFrame * [squaresNumber];
	distance = new int * [squaresNumber];
	for(int i = 0; i < squaresNumber; i++) {
		squares[i] = new SquareWithFrame [squaresNumber];
		distance[i] = new int [squaresNumber];

		for(int j = 0; j < squaresNumber; j++) {
			squares[i][j].setSquareSize(squareSize);
			squares[i][j].setFrameSize(frameSize);
			squares[i][j].setPosition(Vector2f{i * squareSize, j * squareSize});
			distance[i][j] = -1;
		}
	}
}

void Plane::setStartSquare(pair<int, int> startSquare) {
	this->startSquare = startSquare;
	squares[startSquare.first][startSquare.second].setSquareColor(Color::White);
}

void Plane::setEndSquare(pair<int, int> endSquare) {
	this->endSquare = endSquare;
	squares[endSquare.first][endSquare.second].setSquareColor(Color::White);
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

	if(Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		this->isDrawing = false;
		dfs();
	}
}

void Plane::draw(RenderTarget &target, RenderStates state) const {
	for(int i = 0; i < this->squaresNumber; i++) {
		for(int j = 0; j < this->squaresNumber; j++) {
			target.draw(this->squares[i][j], state);
		}
	}
}

void Plane::dfs() {
	if(this->isDrawing || !this->isDfsAvaliable)
		return;

	q.push(this->startSquare);
	point = this->startSquare;
	distance[point.first][point.second] = 0;

	while(!q.empty()) {
		point = q.front();
		q.pop();

		if(point.first != 0) {
			temp = make_pair(point.first - 1, point.second);
			dfsHelp();
			if(!this->isDfsAvaliable)
				break;
		}

		if(point.first != this->squaresNumber - 1) {
			temp = make_pair(point.first + 1, point.second);
			dfsHelp();
			if(!this->isDfsAvaliable)
				break;
		}

		if(point.second != 0) {
			temp = make_pair(point.first, point.second - 1);
			dfsHelp();
			if(!this->isDfsAvaliable)
				break;
		}

		if(point.second != this->squaresNumber - 1) {
			temp = make_pair(point.first, point.second + 1);
			dfsHelp();
			if(!this->isDfsAvaliable)
				break;
		}
	}

	this->isDfsAvaliable = false;
}

void Plane::dfsHelp() {
	if(this->distance[temp.first][temp.second] == -1
	  && this->squares[temp.first][temp.second].getSquareColor() != Color::Yellow) {
		this->distance[temp.first][temp.second] = this->distance[point.first][point.second];

		if(temp == this->endSquare) {
			this->isDfsAvaliable = false;
			return;
		}

		q.push(temp);
		this->squares[temp.first][temp.second].setSquareColor(Color::Red);
	}
}