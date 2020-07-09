#include "frame.h"

using namespace sf;

Frame::Frame() {
}

void Frame::draw(RenderTarget &target, RenderStates state) const {
	target.draw(topShape, state);
	target.draw(bottomShape, state);
	target.draw(leftShape, state);
	target.draw(rightShape, state);
}