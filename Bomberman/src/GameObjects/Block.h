//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_BLOCK_H
#define BOMBERMAN_BLOCK_H

#include "GameObject.h"

enum class BlockTypes
{
  WALKABLE = 0,
  DESTRUCTIBLE = 1,
  INDESTRUCTIBLE = 2
};

class Block : public GameObject
{
 public:
  Block(sf::RenderWindow& game_window);
  void init(sf::Texture &block_texture, float x, float y, BlockTypes _block_type = BlockTypes::WALKABLE);

  void setTexture(sf::Texture &new_texture, BlockTypes new_type);

  bool getCenter(GameObject* player);

  BlockTypes getBlockType();

 private:
  BlockTypes block_type;
};

#endif // BOMBERMAN_BLOCK_H
