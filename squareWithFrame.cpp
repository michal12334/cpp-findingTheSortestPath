#include "squareWithFrame.h"

using namespace sf;

SquareWithFrame::SquareWithFrame() :SquareWithFrame(Vector2f{0, 0}, 0, 0) {}

SquareWithFrame::SquareWithFrame(Vector2f position, float squareSize, float frameSize) 
:frame(position, squareSize, frameSize) {
	this->setSquareSize(squareSize);
	this->setFrameSize(frameSize);
	this->setPosition(position);
	this->setSquareColor(Color::Black);
	this->setFrameColor(Color::White);
}

void SquareWithFrame::setPosition(Vector2f position) {
	this->position = position;
	this->shape.setPosition(position);
	this->frame.setPosition(position);
}

Vector2f SquareWithFrame::getPosition() {
	return this->position;
}

void SquareWithFrame::setSquareSize(float size) {
	this->squareSize = size;
	this->shape.setSize(Vector2f{size, size});
	this->frame.setSquareSize(size);
}

float SquareWithFrame::getSquareSize() {
	return this->squareSize;
}

void SquareWithFrame::setSquareColor(Color color) {
	this->squareColor = color;
	this->shape.setFillColor(color);
}

Color SquareWithFrame::getSquareColor() {
	return this->squareColor;
}

void SquareWithFrame::setFrameColor(Color color) {
	this->frameColor = color;
	this->frame.setColor(color);
}

Color SquareWithFrame::getFrameColor() {
	return this->frameColor;
}

void SquareWithFrame::setFrameSize(float size) {
	this->frameSize = size;
	this->frame.setFrameSize(size);
}

float SquareWithFrame::getFrameSize() {
	return this->frameSize;
}

float SquareWithFrame::top() {
	return this->getPosition().y;
}

float SquareWithFrame::bottom() {
	return this->getPosition().y + this->getSquareSize();
}

float SquareWithFrame::left() {
	return this->getPosition().x;
}

float SquareWithFrame::right() {
	return this->getPosition().x + this->getSquareSize();
}

bool SquareWithFrame::isMouseInside(RenderWindow *window) {
	sf::Vector2i mousePosition = Mouse::getPosition(*window);

	return mousePosition.x >= this->left() 
		&& mousePosition.x <= this->right()
		&& mousePosition.y >= this->top()
		&& mousePosition.y <= this->bottom();
}

void SquareWithFrame::draw(RenderTarget &target, RenderStates state) const {
	target.draw(this->shape, state);
	target.draw(this->frame, state);
}