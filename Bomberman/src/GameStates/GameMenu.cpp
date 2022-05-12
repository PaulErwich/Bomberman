//
// Created by MLG Erwich on 12/05/2022.
//

#include "GameMenu.h"
#include "../Extra/Helper.h"

GameMenu::GameMenu(STATE state_id, sf::RenderWindow &game_window, sf::Font& font) :
  GameStateBase(state_id, game_window, font)
{
  transition = STATE::GAME_MENU;
}

bool GameMenu::init()
{
  if (!background_texture_menu.loadFromFile(
        "Data/Backgrounds/start_screen.png"))
  {
    std::cout << "background texture did not load ";
  }
  background_menu.setTexture(background_texture_menu);
  Helper::createText(play_option,
                     *font,"PLAY",50,basic,200,200);
  Helper::createText(quit_option,
                     *font,"QUIT",50,basic,500,200);

  return true;
}

void GameMenu::reset()
{
  GameStateBase::reset();
}

void GameMenu::input(sf::Event event)
{

  if (event.type == sf::Event::MouseButtonPressed)
  {
    sf::Vector2i click = sf::Mouse::getPosition(window);
    if (clickChecker(click,play_option))
    {
      transition = STATE::GAME_PLAY;
    }
    if (clickChecker(click,quit_option))
    {
      transition = STATE::GAME_EXIT;
    }
  }
}

STATE GameMenu::update(float dt)
{
  return transition;
}

void GameMenu::render()
{
  window.draw(background_menu);
  window.draw(play_option);
  window.draw(quit_option);
}
