//
// Created by MLG Erwich on 14/05/2022.
//

#include "Bomb.h"
Bomb::Bomb(sf::RenderWindow& game_window) : GameObject(game_window)
{
  explode = false;
  range = 1;
}

Bomb::~Bomb()
{

}

bool Bomb::init()
{
  visible = false;

  sf::IntRect bomb(0, 0, 16, 16);
  if (!texture.loadFromFile("Data/bomb.png", bomb))
  {
    return false;
  }

  sprite->setTexture(texture);
  sprite->setScale(3, 3);
  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;

  return true;
}

bool Bomb::getExplode() const { return explode; }

void Bomb::spawnBomb(float x, float y)
{
  explode = false;
  sprite->setPosition(x + 8, y + 8);
  visible = true;
  timer.restart();
  setMin();
  calculateMax();
}

bool Bomb::explodeCollision(GameObject *block)
{
  // Check X
  if (!(min.x - (range * block_sz) > block->getMax().x ||
      max.x + (range * block_sz) < block->getMin().x))
  {
    if (!(max.y < block->getMin().y || min.y > block->getMax().y))
    {
      std::cout << "Wide X hit" << std::endl;
      return true;
    }
  }
  // Check y
  if (!(min.y - (range * block_sz) > block->getMax().y ||
           max.y + (range * block_sz) < block->getMin().y))
  {
    if (!(max.x < block->getMin().x || min.x > block->getMax().x))
    {
      std::cout << "Wide Y hit" << std::endl;
      return true;
    }
  }

  return false;
}

void Bomb::update(float dt)
{
    if (timer.getElapsedTime().asSeconds() > 1.5)
    {
      explode = true;
      visible = false;
    }
}
