#include <SFML/Graphics.hpp>
#include "Engine/Utils.h"
#include <iostream>

void clampInsideWindow(sf::Vector2f &pos, sf::FloatRect dim, sf::Vector2f screen)
{
    if (pos.x < 0.f)
    {
        pos.x = 0.f;
    }
    if (pos.x > screen.x - dim.height)
    {
        pos.x = screen.x - dim.height;
    }
    if (pos.y < 0.f)
    {
        pos.y = 0.f;
    }
    if (pos.y > screen.y - dim.width)
    {
        pos.y = screen.y - dim.width;
    }
}

sf::String vectorToString(sf::Vector2f pos)
{
    sf::String str;
    str = "X: " + std::to_string(pos.x) + "   " + "Y: " + std::to_string(pos.y);
    return str;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mini Game");
    sf::Vector2f pos(0.f, 0.f);
    sf::CircleShape shape(50.f, 50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos);
    window.setKeyRepeatEnabled(true);
    sf::Clock gameClock;
    sf::Text debug;
    sf::Font font;
    font.loadFromFile("Fonts/ccR.ttf");
    debug.setFont(font);
    debug.setFillColor(sf::Color(128, 0, 0));
    debug.setCharacterSize(50);
    debug.move(0.f, 25.f);
    debug.setString("DEBUG");
    window.draw(debug);
    

    while (window.isOpen())
    {
        float dt = gameClock.getElapsedTime().asSeconds();
        gameClock.restart();
        float movingDist = 1000.f * dt;
        std::cout << "Offset value: " << movingDist << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            pos.x -= movingDist;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            pos.x += movingDist;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            pos.y -= movingDist;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            pos.y += movingDist;
        }
        shape.setPosition(pos);
        debug.setString(vectorToString(pos));
        clampInsideWindow(pos, shape.getLocalBounds(), window.getView().getSize());
        window.clear();
        window.draw(shape);
        window.draw(debug);
        window.display();
    }

    return 0;
}