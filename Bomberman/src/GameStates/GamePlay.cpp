//
// Created by MLG Erwich on 12/05/2022.
//

#include "GamePlay.h"
GamePlay::GamePlay(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& font) :
  GameStateBase(state_id, game_window, font)
{
  level = new Level(window);
  player = new Entity();
}

GamePlay::~GamePlay()
{
  delete level;
}

bool GamePlay::init()
{
  if (!Level::loadAssets())
  {
    return false;
  }

  if (!level->init(player))
  {
    return false;
  }

  return true;
}

void GamePlay::reset()
{
  GameStateBase::reset();
}

void GamePlay::input(sf::Event event)
{
  GameStateBase::input(event);
}

STATE GamePlay::update(float dt)
{
  return GameStateBase::update(dt);
}

void GamePlay::render()
{
  level->render();
}
