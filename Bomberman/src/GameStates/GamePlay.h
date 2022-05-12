//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAMEPLAY_H
#define BOMBERMAN_GAMEPLAY_H

#include "GameStateBase.h"

#include "../GameObjects/Level.h"
#include "../GameObjects/Entity.h"

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow &game_window, sf::Font& font);
  ~GamePlay();

  bool init() override;

  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:

  Level *level;
  Entity *player;
};

#endif // BOMBERMAN_GAMEPLAY_H
