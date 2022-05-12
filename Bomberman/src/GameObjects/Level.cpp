//
// Created by MLG Erwich on 12/05/2022.
//

#include "Level.h"

sf::Image Level::WORLD_IMAGE;

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
  init_setup_blocks();

  return true;
}

bool Level::loadAssets()
{
  if (!WORLD_IMAGE.loadFromFile("Data/city-tiles/Spritesheet/roguelikeCity_magenta.png"))
  {
    return false;
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
  sf::IntRect temp(0, 0, 16, 16);

  int indestructibleX = 2, indestructibleY = 5;
  int destructibleX = 10, destructibleY = 5;
  int walkableX = 11, walkableY = 19;

  for (int i = 0; i < HEIGHT; i ++)
  {
    for (int j = 0; j < WIDTH; j ++)
    {
      if (i % 2 == 0)
      {
        if (j % 2)
        {
          temp.top = destructibleY* 16 + destructibleY;
          temp.left = destructibleX * 16 + destructibleX;
          texture.loadFromImage(WORLD_IMAGE, temp);
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ);
        }
        else
        {
          temp.top = walkableY * 16 + walkableY;
          temp.left = walkableX * 16 + walkableX;
          texture.loadFromImage(WORLD_IMAGE, temp);
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ);
        }
      }
      else
      {
        if (j % 2 == 0)
        {
          temp.top = destructibleY * 16 + destructibleY;
          temp.left = destructibleX * 16 + destructibleX;
          texture.loadFromImage(WORLD_IMAGE, temp);
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ);
        }
        else
        {
          temp.top = indestructibleY * 16 + indestructibleY;
          temp.left = indestructibleX * 16 + indestructibleX;
          texture.loadFromImage(WORLD_IMAGE, temp);
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ);
        }
      }
    }
  }

  temp.top = walkableY * 16 + walkableY;
  temp.left = walkableX * 16 + walkableX;
  texture.loadFromImage(WORLD_IMAGE, temp);

  world[0 * WIDTH + 1]->setTexture(texture);
  world[0 * WIDTH + 9]->setTexture(texture);

  world[1 * WIDTH + 0]->setTexture(texture);
  world[1 * WIDTH + 10]->setTexture(texture);

  world[9 * WIDTH + 0]->setTexture(texture);
  world[9 * WIDTH + 10]->setTexture(texture);

  world[10 * WIDTH + 1]->setTexture(texture);
  world[10 * WIDTH + 9]->setTexture(texture);
}
