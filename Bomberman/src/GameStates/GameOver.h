//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAMEOVER_H
#define BOMBERMAN_GAMEOVER_H

#include "GameStateBase.h"

class GameOver : public GameStateBase
{
 public:
  explicit GameOver(STATE state_id, sf::RenderWindow&
                                     game_window, sf::Font &game_font);
  bool init() override;
  void input(sf::Event event)override;
  STATE update(float dt) override;
  void render() override;

 private:
  STATE transition;
  sf::Text return_Game_Menu;
  sf::Text quit_option;
  sf::Sprite background_Game_Won;
  sf::Texture background_texture_Game_Won;
};

#endif // BOMBERMAN_GAMEOVER_H
