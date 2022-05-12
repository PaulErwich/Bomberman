//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_LEVEL_H
#define BOMBERMAN_LEVEL_H

#include "GameObject.h"
#include "Block.h"
#include "../GameStates/GameStateBase.h"
#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Level
{
 public:
  Level(sf::RenderWindow& game_window);
  ~Level();

  bool init(Entity* _player);
  static bool loadAssets();

  void reset();

  void input(sf::Event event);
  STATE update(float dt);
  void render();

  static sf::Image WORLD_IMAGE;

 private:
  sf::RenderWindow &window;

  static const int WIDTH = 11;
  static const int HEIGHT = 11;
  static const int BLOCK_SZ = 64;

  sf::Texture texture;



  Block *world[WIDTH * HEIGHT]; // Textures

  Entity* player;

  void init_setup_blocks();


};

#endif // BOMBERMAN_LEVEL_H
