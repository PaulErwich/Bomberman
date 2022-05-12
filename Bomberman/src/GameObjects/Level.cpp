//
// Created by MLG Erwich on 12/05/2022.
//

#include "Level.h"

sf::Texture Level::WORLD_TEXTURE[TEXTURE_NUM];

Level::Level(sf::RenderWindow& game_window) : window(game_window)
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i] = new Block(window);
  }
}
Level::~Level()
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    delete world[i];
  }
}

bool Level::init(Entity* _player)
{
  return false;
}

bool Level::loadAssets()
{
  // 16 x 16 with 1 pixel gap

  for (int i = 0; i < 28; i++)
  {
    for (int j = 0; j < 37; j++)
    {
      sf::IntRect temp(0 + (j * 16 + 1), 0 + (i * 16 + 1), 16, 16);
      if (!WORLD_TEXTURE[i + j * 28].loadFromFile("Data/city-tiles/Spritesheet/roguelikeCity_magenta.png", temp))
      {
        return false;
      }
    }
  }

  return true;
}

void Level::reset() {}

void Level::input(sf::Event event) {}

STATE Level::update(float dt)
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i]->update(dt);
  }

  return STATE::GAME_PLAY;
}

void Level::render()
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i]->render();
  }
}

void Level::init_setup_blocks()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      world[i + j * HEIGHT]->init()
    }
  }
}
