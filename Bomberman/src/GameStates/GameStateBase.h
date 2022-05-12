//
// Created by MLG Erwich on 12/05/2022.
//

#ifndef BOMBERMAN_GAMESTATEBASE_H
#define BOMBERMAN_GAMESTATEBASE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

enum class STATE
{
  GAME_UNKNOWN = -1,
  GAME_EXIT = 0,
  GAME_MENU = 1,
  GAME_PLAY = 2,
  GAME_PAUSED = 3,
  GAME_OVER = 4,
  GAME_WIN = 5
};

class GameStateBase
{
 public:
  GameStateBase(STATE state_id, sf::RenderWindow& game_window, sf::Font &game_font);
  ~GameStateBase() = default;
  virtual bool init();
  STATE getStateID();
  virtual void reset();
  virtual void input(sf::Event event);
  virtual STATE update(float dt);
  virtual void render();

 protected:
  static bool clickChecker(sf::Vector2i click, const sf::Text& area);
  static bool spriteClickChecker(sf::Vector2i click, const sf::Sprite& area);

  STATE game_state_id;
  sf::RenderWindow& window;
  sf::Font *font;

  const sf::Color basic = sf::Color::Black;
};

#endif // BOMBERMAN_GAMESTATEBASE_H
