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

  for (int i = 0; i < MAX_BOMB; i++)
  {
    bombs[i] = new Bomb(window);
  }

  enemy = new Enemy(window, MAP);

  active_bombs = 0;

  MAP = {
    {0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    {0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0},
    {0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
  };
}

Level::~Level()
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    delete world[i];
  }

  for (int i = 0; i < MAX_BOMB; i++)
  {
    delete bombs[i];
  }

  delete enemy;
}

bool Level::init(Entity* _player)
{
  init_setup_blocks();
  player = _player;

  for (int i = 0; i < MAX_BOMB; i++)
  {
    bombs[i]->init();
  }

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

void Level::input(sf::Event event)
{
  player->input(event);

  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Space && timer.getElapsedTime().asSeconds() > 1)
    {
      if (!bombs[active_bombs]->getVisible())
      {
        for (int i = 0; i < WIDTH * HEIGHT; i++)
        {
          if (world[i]->getCenter(player))
          {
            bombs[active_bombs]->spawnBomb(world[i]->getMin().x, world[i]->getMin().y);
            break;
          }
        }

        timer.restart();
        if (active_bombs == MAX_BOMB - 1) { active_bombs = 0; }
        else { active_bombs++; }
      }
    }
  }
}

STATE Level::update(float dt)
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i]->update(dt);
  }

  for (int i = 0; i < MAX_BOMB; i++)
  {
    if (bombs[i]->getVisible())
    {
      bombs[i]->update(dt);

      if (bombs[i]->getExplode())
      {
        for (int j = 0; j < HEIGHT; j++)
        {
          for (int k = 0; k < WIDTH; k++)
          {
            if (world[j * WIDTH + k]->getBlockType() == BlockTypes::DESTRUCTIBLE)
            {
              if (bombs[i]->explodeCollision(world[j * WIDTH + k]))
              {
                world[j * WIDTH + k]->setTexture(texture, BlockTypes::WALKABLE);
                MAP[j][k] = 0;
                //for (int l = 0; l < HEIGHT; l++)
                //{
                //  for (int m = 0; m < WIDTH; m++)
                //  {
                //    std::cout << MAP[l][m];
                //  }
                //  std::cout << std::endl;
                //}
              }
            }
          }
        }
      }
    }
  }

  enemy->update(dt);

  player->update(dt);

  Object_Manifold collision(player, nullptr);

  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    collision.B = world[i];

    if (AABBvsAABB_MK3(&collision))
    {
      if (world[i]->getBlockType() != BlockTypes::WALKABLE)
      {
        std::cout << "HIT " + std::to_string(i) << std::endl;
        if (collision.normal.x != 0)
        {
          if (collision.normal.x == 1)
          {
            player->getSprite()->setPosition(collision.B->getMin().x - player->getWidth(), player->getSprite()->getPosition().y);
          }
          else if (collision.normal.x == -1)
          {
            player->getSprite()->setPosition(collision.B->getMax().x, player->getSprite()->getPosition().y);
          }
        }
        else if (collision.normal.y != 0)
        {
          if (collision.normal.y == 1)
          {
            player->getSprite()->setPosition(player->getSprite()->getPosition().x, collision.B->getMin().y - player->getHeight());
          }
          else if (collision.normal.y == -1)
          {
            player->getSprite()->setPosition(player->getSprite()->getPosition().x, collision.B->getMax().y);
          }
        }
      }
    }
  }

  if (player->getMin().x < world[0]->getMin().x)
  {
    player->getSprite()->setPosition(world[0]->getMin().x, player->getSprite()->getPosition().y);
  }
  else if (player->getMax().x > world[HEIGHT * WIDTH - 1]->getMax().x)
  {
    player->getSprite()->setPosition(world[HEIGHT * WIDTH - 1]->getMax().x - player->getWidth(), player->getSprite()->getPosition().y);
  }

  if (player->getMin().y < world[0]->getMin().y)
  {
    player->getSprite()->setPosition(player->getSprite()->getPosition().x ,world[0]->getMin().y);
  }
  else if (player->getMax().y > world[HEIGHT * WIDTH - 1]->getMax().y)
  {
    player->getSprite()->setPosition(player->getSprite()->getPosition().x, world[HEIGHT * WIDTH - 1]->getMax().y - player->getHeight());
  }

  return STATE::GAME_PLAY;
}

void Level::render()
{
  for (int i = 0; i < WIDTH * HEIGHT; i++)
  {
    world[i]->render();
  }
  player->render();

  enemy->render();

  for (int i = 0; i < MAX_BOMB; i++)
  {
    bombs[i]->render();
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
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ, BlockTypes::DESTRUCTIBLE);
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
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ, BlockTypes::DESTRUCTIBLE);
        }
        else
        {
          temp.top = indestructibleY * 16 + indestructibleY;
          temp.left = indestructibleX * 16 + indestructibleX;
          texture.loadFromImage(WORLD_IMAGE, temp);
          world[i * WIDTH + j]->init(texture, j * BLOCK_SZ, i * BLOCK_SZ, BlockTypes::INDESTRUCTIBLE);
        }
      }
    }
  }

  temp.top = walkableY * 16 + walkableY;
  temp.left = walkableX * 16 + walkableX;
  texture.loadFromImage(WORLD_IMAGE, temp);

  world[0 * WIDTH + 1]->setTexture(texture, BlockTypes::WALKABLE);
  world[0 * WIDTH + 9]->setTexture(texture, BlockTypes::WALKABLE);

  world[1 * WIDTH + 0]->setTexture(texture, BlockTypes::WALKABLE);
  world[1 * WIDTH + 10]->setTexture(texture, BlockTypes::WALKABLE);

  world[9 * WIDTH + 0]->setTexture(texture, BlockTypes::WALKABLE);
  world[9 * WIDTH + 10]->setTexture(texture, BlockTypes::WALKABLE);

  world[10 * WIDTH + 1]->setTexture(texture, BlockTypes::WALKABLE);
  world[10 * WIDTH + 9]->setTexture(texture, BlockTypes::WALKABLE);
}
