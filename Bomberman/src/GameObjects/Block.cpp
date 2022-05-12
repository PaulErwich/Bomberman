//
// Created by MLG Erwich on 12/05/2022.
//

#include "Block.h"

Block::Block(sf::RenderWindow& game_window) :
  GameObject(game_window)
{

}

void Block::init(sf::Texture& block_texture, float x, float y)
{
  texture = block_texture;

  sprite->setTexture(texture);
  float scale = 4;
  sprite->scale(scale, scale);

  int excess = 98;
  sprite->setPosition(x + excess, y + excess);

  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;
  setMin();
  calculateMax();
}

void Block::setTexture(sf::Texture& new_texture)
{
  sprite->setTexture(new_texture);
}
