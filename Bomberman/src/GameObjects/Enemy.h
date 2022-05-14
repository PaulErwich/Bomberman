//
// Created by MLG Erwich on 14/05/2022.
//

#ifndef BOMBERMAN_ENEMY_H
#define BOMBERMAN_ENEMY_H

#include "Entity.h"
#include <vector>

class Enemy : public Entity
{
 public:
  Enemy(sf::RenderWindow& game_window, std::vector<std::vector<int>> &_map);
  ~Enemy();

  void setPos(float x, float y);

  void update(float dt) override;

 private:
  std::vector<std::vector<int>> *map;
};

#endif // BOMBERMAN_ENEMY_H
