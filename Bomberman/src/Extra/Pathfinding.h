//
// Created by MLG Erwich on 18/05/2022.
//

#ifndef BOMBERMAN_PATHFINDING_H
#define BOMBERMAN_PATHFINDING_H

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstdlib>

#include "Vector2.h"

using std::vector;
using std::pair;

struct GridLocation { int x, y; };

namespace std
{
  template<> struct hash<GridLocation>
  {
    std::size_t operator()(const GridLocation& id) const noexcept
    {
      return std::hash<int>()(id.x ^ (id.y << 16));
    }
  };
}

struct SquareGrid
{
  static std::array<GridLocation, 4> DIRS;

  int width, height;
  std::unordered_set<GridLocation> walls;

  SquareGrid(int _width, int _height) : width(_width), height(_height) {}

  bool in_bounds(GridLocation id) const { return 0 <= id.x && id.x < width &&
           0 <= id.y && id.y < height;}

  bool passable(GridLocation id) const {return walls.find(id) == walls.end(); }

  vector<GridLocation> neighbors(GridLocation id) const
  {
    vector<GridLocation> results;

    for (GridLocation dir : DIRS)
    {
      GridLocation next{id.x + dir.x, id.y + dir.y};
      if (in_bounds(next) && passable(next))
      {
        results.push_back(next);
      }
    }

    if ((id.x + id.y) % 2 == 0)
    {
      std::reverse(results.begin(), results.end());
    }

    return results;
  }
};

std::array<GridLocation, 4> SquareGrid::DIRS = {
  GridLocation{1, 0}, GridLocation{-1, 0},
  GridLocation{0, -1}, GridLocation{0, 1}
};

bool operator == (GridLocation a, GridLocation b)
{ return a.x == b.x && a.y == b.y; }

bool operator != (GridLocation a, GridLocation b)
{ return !(a == b); }

bool operator < (GridLocation a, GridLocation b)
{ return std::tie(a.x, a.y) < std::tie(b.x, b.y); }

std::basic_iostream<char>::basic_ostream& operator<<(std::basic_iostream<char>::basic_ostream& out,
                                                     const GridLocation& loc)
{
  out << '(' << loc.x << ',' << loc.y << ')';
  return out;
}

vector<Vector2> get_neighbours(const vector<vector<int>>& game_map, const Vector2& node,
                                   int map_width, int map_height);

inline double heuristic(const Vector2& a, const Vector2& b);

template<typename Location, typename Graph>
void a_star(Graph graph, Vector2 start, Vector2 end,
            std::unordered_map<Location, Location>& came_from,
            std::unordered_map<Location, double>& cost_so_far);

template<typename T, typename priority_t>
struct PriorityQueue
{
  typedef pair<priority_t, T> PQElement;

  std::priority_queue<PQElement, vector<PQElement>,
                      std::greater<PQElement>> elements;

  inline bool empty() const {return elements.empty(); }

  inline void put(T item, priority_t priority) {elements.emplace(priority, item); }

  T get()
  {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};

#endif // BOMBERMAN_PATHFINDING_H
