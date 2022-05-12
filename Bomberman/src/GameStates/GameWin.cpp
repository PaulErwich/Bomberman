#include "GameWin.h"
#include "../Extra/Helper.h"

GameWin::GameWin(STATE state_id, sf::RenderWindow& game_window,
                 sf::Font &game_font) :
  GameStateBase(state_id, game_window, game_font)
{
  transition = game_state_id;
}
  bool GameWin::init()
{
  if (!background_texture_Game_Won.loadFromFile(
        "Data/Backgrounds/start_screen.png"))
  {
    std::cout << "background texture did not load ";
  }
  background_Game_Won.setTexture(background_texture_Game_Won);
  Helper::createText(return_Game_Menu,
                     *font,"Return to Menu",50,basic,200,200);
  Helper::createText(quit_option,
                     *font,"QUIT",50,basic,500,200);
  return true;
}

void GameWin::input(sf::Event event)
{
  if (event.type == sf::Event::MouseButtonPressed)
  {
    sf::Vector2i click = sf::Mouse::getPosition(window);
    if (clickChecker(click,return_Game_Menu))
    {
      transition = STATE::GAME_MENU;
    }
    if (clickChecker(click,quit_option))
    {
      transition = STATE::GAME_EXIT;
    }
  }
}

STATE GameWin::update(float dt)
{
  return transition;
}

void GameWin::render()
{
  GameStateBase::render();
}

