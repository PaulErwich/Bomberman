//
// Created by MLG Erwich on 14/05/2022.
//

#ifndef BOMBERMAN_OBJECTSTRUCTURES_H
#define BOMBERMAN_OBJECTSTRUCTURES_H

#include "../Extra/Vector2.h"
#include "../GameObjects/GameObject.h"

struct AABB
{
  Vector2 min = Vector2(0, 0);
  Vector2 max = Vector2(0, 0);
};

struct MassData
{
  MassData();
  MassData(float _mass);

  float mass;
  // Remember to calculate this 1 / mass
  float inv_mass;
};

struct Material
{
  Material();
  Material(float _density, float _restitution);

  float density = 0;
  float restitution = 0;
};

struct Body
{
  Body();
  Body(GameObject *_gameObject, float _density, float _restitution);

  GameObject *gameObject;
  Material material;
  MassData mass_data;
  Vector2 velocity;
  Vector2 force;
  //float gravityScale; // Real number
};

struct Manifold
{
  Manifold();
  Manifold(Body* a, Body* b);

  Body *A;
  Body *B;
  float penetration;
  Vector2 normal;
};

struct Object_Manifold
{
  Object_Manifold();
  Object_Manifold(GameObject *a, GameObject *b);

  GameObject *A;
  GameObject *B;

  float penetration;
  Vector2 normal;
};

#endif // BOMBERMAN_OBJECTSTRUCTURES_H
