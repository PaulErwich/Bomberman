//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAMEWIN_H
#define BOMBERMAN_GAMEWIN_H

#include "GameStateBase.h"

class GameWin : public GameStateBase
{
 public:
  explicit GameWin(STATE state_id, sf::RenderWindow&
                                     game_window, sf::Font &game_font);
  ~GameWin() = default;
  bool init() override;
  void input(sf::Event event)override;
  STATE update(float dt) override;
  void render() override;

 private:
  bool transition;
  sf::Text game_Won_text;
  sf::Text return_Game_Menu;
  sf::Text quit_option;
  sf::Sprite background_Game_Won;
  sf::Texture background_texture_Game_Won;
};

#endif // BOMBERMAN_GAMEWIN_H
