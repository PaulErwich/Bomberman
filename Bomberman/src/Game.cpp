//
// Created by MLG Erwich on 12/05/2022.
//

#include "Game.h"
Game::Game(sf::RenderWindow& window) : window(window)
{

}
Game::~Game() {}

bool Game::init()
{
  return true;
}

void Game::input(sf::Event event) {}
void Game::update(float dt) {}
void Game::render() {}
