//
// Created by MLG Erwich on 12/05/2022.
//

#include "GamePlay.h"
GamePlay::GamePlay(
  STATE state_id, sf::RenderWindow& game_window, sf::Font& font) :
  GameStateBase(state_id, game_window, font)
{
  level = new Level(window);
  player = new Entity(window);
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

  if (!player->init())
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
  level->input(event);
}

STATE GamePlay::update(float dt)
{
  return level->update(dt);;
}

void GamePlay::render()
{
  level->render();
}
