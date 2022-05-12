//
// Created by MLG Erwich& scott on 12/05/2022.
//

#include "GamePaused.h"
GamePaused::GamePaused(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& font) :
  GameStateBase(state_id, game_window, font)
{
}
bool GamePaused::init()
{
  return true;
}
void GamePaused::reset()
{
  GameStateBase::reset();
}
void GamePaused::input(sf::Event event)
{
  GameStateBase::input(event);
}
STATE GamePaused::update(float dt)
{
  return GameStateBase::update(dt);
}
void GamePaused::render()
{
  GameStateBase::render();
}
