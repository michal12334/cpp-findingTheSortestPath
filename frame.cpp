#include "frame.h"

using namespace sf;

Frame::Frame(Vector2f position, float squareSize, float frameSize) {
	this->setSquareSize(squareSize);
	this->setFrameSize(frameSize);
	this->setPosition(position);
	this->setColor(Color::White);
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

void Frame::setFrameSize(float frameSize) {
	this->frameSize = frameSize;
	this->topShape.setSize(Vector2f{this->squareSize, this->frameSize});
	this->bottomShape.setSize(Vector2f{this->squareSize, this->frameSize});
	this->leftShape.setSize(Vector2f{this->frameSize, this->squareSize});
	this->rightShape.setSize(Vector2f{this->frameSize, this->squareSize});
}

float Frame::getFrameSize() {
	return this->frameSize;
}

void Frame::setColor(Color color) {
	this->color = color;
	this->topShape.setFillColor(this->color);
	this->bottomShape.setFillColor(this->color);
	this->leftShape.setFillColor(this->color);
	this->rightShape.setFillColor(this->color);
}

Color Frame::getColor() {
	return this->color;
}

void Frame::draw(RenderTarget &target, RenderStates state) const {
	target.draw(this->topShape, state);
	target.draw(this->bottomShape, state);
	target.draw(this->leftShape, state);
	target.draw(this->rightShape, state);
}