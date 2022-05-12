//
// Created by MLG Erwich on 12/05/2022.
//

#include "GameObject.h"
GameObject::GameObject(sf::RenderWindow& game_window) : window(game_window)
{
  sprite = new sf::Sprite();
  visible = true;
  width = 0;
  height = 0;
}

GameObject::~GameObject()
{
  delete sprite;
}

sf::Sprite* GameObject::getSprite() { return sprite; }

bool GameObject::getVisible() const { return visible; }
void GameObject::setVisible(bool visibility) { visible = visibility; }

bool GameObject::init() { return true; }

void GameObject::update(float dt) {}

void GameObject::render() { window.draw(*sprite); }

void GameObject::setMin() { min = Vector2(sprite->getPosition().x, sprite->getPosition().y); }
Vector2 GameObject::getMin() { return min; }

void GameObject::calculateMax()
{
  max.x = min.x + width;
  max.y = min.y + height;
}
Vector2 GameObject::getMax() { return max; }

float GameObject::getWidth() const { return width; }
float GameObject::getHeight() const { return height; }

void GameObject::setWidth(float _width) { width = _width; }
void GameObject::setHeight(float _height) { height = _height; }

Vector2 GameObject::getMovement() { return movement; }

void GameObject::setMovement(const Vector2& move) {movement = move; }

bool GameObject::AABB(GameObject* collider) const
{
  if (max.x < collider->min.x || min.x > collider->max.x) return false;
  if (max.y < collider->min.y || min.y > collider->max.y) return false;

  return true;
}
