#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(900, 900), "Bomberman");
    window.setFramerateLimit(60);

    Game game(window);

    if (!game.init())
    {
      return 0;
    }

    sf::Clock clock;

    while(window.isOpen())
    {
      sf::Event event;

      sf::Time time = clock.restart();
      float dt = time.asSeconds();

      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
        {
          window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed ||
            event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseMoved)
        {
          game.input(event);
        }
      }

      game.update(dt);

      window.clear(sf::Color::Black);

      game.render();
      window.display();
    }

    return 0;
}
