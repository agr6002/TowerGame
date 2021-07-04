#pragma once
#include "Actor.hpp"
#include "Vector2.hpp"

class ModelAble : public virtual Actor
{
public:
  static void SetModel(class Model *Model);
  static void SetPath(std::vector<Vector2> path, std::vector<Vector2> bugsSpots, 
      std::vector<Vector2> cornSpots);

  ModelAble(class Model &model, int col, int row);

  void ChangePos(float dx, float dy);
  void FollowPath();
  void NextMove();
  bool IsInVector(Vector2 part, std::vector<Vector2> vector);

private:
  static class Model *model;
  static std::vector<Vector2> path;
  static std::vector<Vector2> cornSpots;

  Vector2 lastRowCol = {0, 0};
  Vector2 change = {0, 0};
};
