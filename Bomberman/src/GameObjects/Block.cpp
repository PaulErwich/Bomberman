//
// Created by MLG Erwich on 12/05/2022.
//

#include "Block.h"

Block::Block(sf::RenderWindow& game_window) :
  GameObject(game_window)
{
}

void Block::init(sf::Texture& block_texture, float x, float y, BlockTypes _block_type)
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

  block_type = _block_type;
}

void Block::setTexture(sf::Texture& new_texture, BlockTypes new_type)
{
  sprite->setTexture(new_texture);
  block_type = new_type;
}

bool Block::getCenter(GameObject* player)
{
  Vector2 player_pos(player->getSprite()->getPosition().x + player->getWidth() / 2,
                       player->getSprite()->getPosition().y + player->getHeight() / 2);

  if (player_pos.x > min.x && player_pos.x < max.x)
  {
    if (player_pos.y > min.y && player_pos.y < max.y)
    {
      return true;
    }
  }
  return false;
}

BlockTypes Block::getBlockType() { return block_type; }