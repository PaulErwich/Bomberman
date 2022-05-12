//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAMEPAUSED_H
#define BOMBERMAN_GAMEPAUSED_H

#include "GameStateBase.h"

class GamePaused : public GameStateBase
{
 public:
  GamePaused(STATE state_id, sf::RenderWindow &game_window, sf::Font& font);

  bool init() override;

  void reset() override;
  void input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Text menu_text;
  sf::Text play_option;
  sf::Text quit_option;
  sf::Sprite background_menu;
  sf::Texture background_texture_menu;
  sf::Font font;
};

#endif // BOMBERMAN_GAMEPAUSED_H
