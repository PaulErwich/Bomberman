//
// Created by MLG Erwich on 12/05/2022.
//

#include "Entity.h"
Entity::Entity(sf::RenderWindow& game_window) : GameObject(game_window)
{

}

Entity::~Entity()
{

}

bool Entity::init()
{
  sf::IntRect player(68, 24, 16, 24);
  if (!texture.loadFromFile("Data/players.png", player))
  {
    return false;
  }

  sprite->setTexture(texture);
  sprite->setPosition(98, 98);
  sprite->scale(2.5, 2.5);

  width = sprite->getGlobalBounds().width;
  height = sprite->getGlobalBounds().height;
  setMin();
  calculateMax();

  return true;
}

void Entity::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::W) movement.y = -1;
    if (event.key.code == sf::Keyboard::S) movement.y = 1;
    if (event.key.code == sf::Keyboard::A) movement.x = -1;
    if (event.key.code == sf::Keyboard::D) movement.x = 1;
  }

  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S) movement.y = 0;
    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) movement.x = 0;
  }

}

void Entity::update(float dt)
{
  if (movement.x == 0)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x = -1;
  }
  if (movement.y == 0)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y = -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y = 1;
  }

  sprite->move(movement.x * dt * SPEED, movement.y * dt * SPEED);
  setMin();
  calculateMax();
}
