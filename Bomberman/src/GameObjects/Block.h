//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_BLOCK_H
#define BOMBERMAN_BLOCK_H

#include "GameObject.h"

class Block : public GameObject
{
 public:
  Block(sf::RenderWindow& game_window);
  void init(sf::Texture &block_texture, float x, float y);

  void setTexture(sf::Texture &new_texture);
};

#endif // BOMBERMAN_BLOCK_H
