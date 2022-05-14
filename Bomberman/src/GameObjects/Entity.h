//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_ENTITY_H
#define BOMBERMAN_ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
 public:
  Entity(sf::RenderWindow &game_window);
  ~Entity();

  bool init() override;

  void input(sf::Event event);

  void update(float dt) override;

 private:
  static const int SPEED = 200;
};

#endif // BOMBERMAN_ENTITY_H
