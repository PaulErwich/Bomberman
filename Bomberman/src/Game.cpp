//
// Created by MLG Erwich on 12/05/2022.
//

#include "Game.h"
Game::Game(sf::RenderWindow& window) : window(window)
{
  font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf");

  game_menu = new GameMenu(STATE::GAME_MENU, window, font);
  game_play = new GamePlay(STATE::GAME_PLAY, window, font);
  game_paused = new GamePaused(STATE::GAME_PAUSED, window, font);
  game_over = new GameOver(STATE::GAME_OVER, window, font);
  game_win = new GameWin(STATE::GAME_WIN, window, font);

  current_state = game_menu;
}
Game::~Game()
{
  delete game_menu;
  delete game_play;
  delete game_paused;
  delete game_over;
  delete game_win;

  delete current_state;
}

bool Game::init()
{
  if (game_menu->init() && game_play->init() &&
      game_paused->init() && game_over->init() && game_win->init())
  {
    return true;
  }
  return false;
}

void Game::input(sf::Event event) { current_state->input(event); }

void Game::update(float dt)
{
  STATE new_state = current_state->update(dt);

  if (new_state == current_state->getStateID())
  {

  }
  else
  {
    switch(new_state)
    {
      case STATE::GAME_EXIT:
        window.close();
        break;
      case STATE::GAME_MENU:
        game_menu->reset();
        current_state = game_menu;
        break;
      case STATE::GAME_PLAY:
        current_state = game_play;
        break;
      case STATE::GAME_PAUSED:
        game_paused->reset();
        current_state = game_paused;
        break;
      case STATE::GAME_OVER:
        current_state = game_over;
        break;
      case STATE::GAME_WIN:
        current_state = game_win;
        break;
      case STATE::GAME_UNKNOWN:
        std::cout << "Unable to handle game state";
        break;
      default:
        std::cout << "unknown state";
        window.close();
        break;
    }
  }
}
void Game::render() { current_state->render(); }
