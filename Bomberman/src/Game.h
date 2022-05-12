//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
 public:
  Game(sf::RenderWindow &window);
  ~Game();

  bool init();

  void input(sf::Event event);
  void update(float dt);
  void render();

 private:
  sf::RenderWindow& window;

};


#endif //BOMBERMAN_GAME_H
