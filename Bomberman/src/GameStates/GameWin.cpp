//
// Created by MLG Erwich on 12/05/2022.
//

#include "GameWin.h"
GameWin::GameWin(STATE state_id, sf::RenderWindow& game_window,
                 sf::Font &game_font) :
  GameStateBase(state_id, game_window, game_font)
{
  transition = false;
}
bool GameWin::init()
{
  return true;
}

void GameWin::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      transition = true;
    }
  }

}

STATE GameWin::update(float dt)
{
  if (transition) return STATE::GAME_MENU;

  return game_state_id;

}

void GameWin::render()
{
  GameStateBase::render();
}

