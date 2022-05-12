//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAMEMENU_H
#define BOMBERMAN_GAMEMENU_H

#include "GameStateBase.h"

class GameMenu : public GameStateBase
{
 public:
  GameMenu(STATE state_id, sf::RenderWindow &game_window, sf::Font& font);

  bool init() override;

  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  STATE transition;
  sf::Text play_option;
  sf::Text quit_option;
  sf::Sprite background_menu;
  sf::Texture background_texture_menu;
};

#endif // BOMBERMAN_GAMEMENU_H
