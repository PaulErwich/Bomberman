//
// Created by MLG Erwich on 18/05/2022.
//

#include "Pathfinding.h"

vector<Vector2> get_neighbours(const vector<vector<int>>& game_map, const Vector2& node,
                                   int map_width, int map_height)
{
  vector<Vector2> neighbours;

  const int TILE = 4;

  Vector2 tile_check[TILE] = {
    Vector2(0, -1),
    Vector2(0, 1),
    Vector2(-1, 0),
    Vector2(1, 0)
  };

  for (int i = 0; i < TILE; i++)
  {
    Vector2 new_pos(node.x + tile_check[i].x, node.y + tile_check[i].y);

    if (new_pos.x > map_width - 1 || new_pos.x < 0 ||
      new_pos.y > map_height - 1 || new_pos.y < 0)
      continue;

    if (game_map[new_pos.x][new_pos.y] == 0)
      continue;

    neighbours.push_back(new_pos);
  }

  return neighbours;
}

inline double heuristic(const Vector2& a, const Vector2& b)
{
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

template<typename Location, typename Graph>
void a_star(Graph graph, Vector2 start, Vector2 end,
            std::unordered_map<Location, Location>& came_from,
            std::unordered_map<Location, double>& cost_so_far)
{
  PriorityQueue<Location, double> frontier;
  frontier.put(start, 0);

  came_from[start] = start;
  cost_so_far[start] = 0;

  while (!frontier.empty())
  {
    Location current = frontier.get();

    if (current == end)
    {
      break;
    }

    for (Location next : )
  }
}