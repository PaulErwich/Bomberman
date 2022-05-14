//
// Created by MLG Erwich on 14/05/2022.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include "GameObject.h"
#include <iostream>

class Bomb : public GameObject
{
 public:
  Bomb(sf::RenderWindow &game_window);
  ~Bomb();

  bool init() override;

  bool getExplode() const;

  void spawnBomb(float x, float y);

  bool explodeCollision(GameObject *block);

  void update(float dt) override;

 private:
  int range;
  sf::Clock timer;
  bool explode;
  static const int block_sz = 64;
};

#endif // BOMBERMAN_BOMB_H
