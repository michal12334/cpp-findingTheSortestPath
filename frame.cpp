#include "frame.h"

using namespace sf;

Frame::Frame() {
}

void Frame::setPosition(Vector2f position) {
	this->position = position;
	this->topShape.setPosition(this->position);
	this->leftShape.setPosition(this->position);

	Vector2f rightPosition;
	rightPosition.y = this->position.y;
	rightPosition.x = this->position.x + this->squareSize - this->frameSize;
	this->rightShape.setPosition(rightPosition);

	Vector2f bottomPosition;
	bottomPosition.x = this->position.x;
	bottomPosition.y = this->position.y + this->squareSize - this->frameSize;
	this->bottomShape.setPosition(bottomPosition);
}

Vector2f Frame::getPosition() {
	return this->position;
}

void Frame::setSquareSize(float squareSize) {
	this->squareSize = squareSize;
}

float Frame::getSquareSize() {
	return this->squareSize;
}

void Frame::draw(RenderTarget &target, RenderStates state) const {
	target.draw(this->topShape, state);
	target.draw(this->bottomShape, state);
	target.draw(this->leftShape, state);
	target.draw(this->rightShape, state);
}