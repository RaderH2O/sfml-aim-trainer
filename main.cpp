#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>

#define WIDTH 640
#define HEIGHT 480

sf::Vector2f randomPosition() {
    return sf::Vector2f(rand()%(WIDTH - 100) + 50, rand()%(HEIGHT - 100) + 50);
}

bool isColliding(float x1, float y1, float x2, float y2, float w2, float h2) {
    if (x1 >= x2 && x1 <= x2+w2 && y1 >= y2 && y1 <= y2+h2)
        return true;
    return false;
}

int main() {
    srand(time(0));
    sf::Vector2f rectPosition = randomPosition();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Aim Trainer", sf::Style::Close);
    sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    rect.setFillColor(sf::Color::White);
    while (window.isOpen()) {
        sf::Event events;
        rect.setPosition(rectPosition);
        while (window.pollEvent(events)) {
            switch (events.type) {
                case events.Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i mousePos = sf::Mouse::getPosition() - window.getPosition();
                    mousePos.y -= 36;
                    if (isColliding(mousePos.x, mousePos.y, rectPosition.x, rectPosition.y, 50.f, 50.f)) {
                        rectPosition = randomPosition();
                    }
                    break;
            }
        }
        window.clear();
        window.draw(rect);
        window.display();
    }
    return 0;
}