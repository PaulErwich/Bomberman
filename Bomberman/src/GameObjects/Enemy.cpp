//
// Created by MLG Erwich on 14/05/2022.
//

#include "Enemy.h"
Enemy::Enemy(sf::RenderWindow& game_window, std::vector<std::vector<int>> &_map) : Entity(game_window)
{
  map = &_map;
}

Enemy::~Enemy()
{

}

void Enemy::setPos(float x, float y)
{
  sprite->setPosition(x, y);
}

void Enemy::update(float dt)
{
  Entity::update(dt);
}
