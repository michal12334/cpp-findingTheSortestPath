#include "squareWithFrame.h"

using namespace sf;

SquareWithFrame::SquareWithFrame() {
}

void SquareWithFrame::draw(RenderTarget &target, RenderStates state) const {
	target.draw(this->shape, state);
	target.draw(this->frame, state);
}