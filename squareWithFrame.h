#pragma once

#include <SFML/Graphics.hpp>
#include "frame.h"

class SquareWithFrame :public sf::Drawable {
public:
	SquareWithFrame();
	SquareWithFrame(sf::Vector2f position, float squareSize, float frameSize);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setSquareSize(float size);
	float getSquareSize();
	void setSquareColor(sf::Color color);
	sf::Color getSquareColor();
	void setFrameColor(sf::Color color);
	sf::Color getFrameColor();
	void setFrameSize(float size);
	float getFrameSize();

	float top();
	float bottom();
	float left();
	float right();
	bool isMouseInside(sf::RenderWindow *window);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	Frame frame;
	sf::Vector2f position;
	float squareSize;
	sf::Color squareColor;
	sf::Color frameColor;
	float frameSize;
	sf::RectangleShape shape;
};