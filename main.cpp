#include <SFML/Graphics.hpp>
#include "squareWithFrame.h"
#include "plane.h"
#include <iostream>

using namespace sf;
using namespace std;

pair<int, int> loadSquare() {
    int x, y;
    cin >> x >> y;
    return make_pair(x, y);
}

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;
    const int SQUARES_NUMBER = 50;
    const float SQUARE_SIZE = 16;
    const float FRAME_SIZE = 1;

    Plane plane(SQUARES_NUMBER, SQUARE_SIZE, FRAME_SIZE);
    plane.setStartSquare(loadSquare());
    plane.setEndSquare(loadSquare());

    RenderWindow window(VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "the sortest path");
    window.setFramerateLimit(60);
    Event event;

    while(true) {
        window.pollEvent(event);

        if(event.type == Event::Closed) {
            window.close();
            break;
        }

        plane.drawOnPlane(&window);
        for(int i = 0; i < 30; i++)
            plane.bfs();
        plane.findTheSortestPath();

        window.clear();
        window.draw(plane);
        window.display();
    }
    return 0;
}