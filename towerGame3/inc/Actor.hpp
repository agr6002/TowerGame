#pragma once
#include <vector>
#include "Vector2.hpp"

class Actor
{
public:
  Actor(class Model &model, int col, int row);
  ~Actor();

  static void SetDim(int dimX, int dimY);
  static int GetDimX() { return dim.x; }
  static int GetDimY() { return dim.y; }
  int GetPosX() { return pos.x; }
  int GetPosY() { return pos.y; }
  class Model GetModel();
  void SetPos(float posX, float posY);
  void SetRowCol(int col, int row);

protected:
  class Model &model;
  std::vector<class Component *> components;
  Vector2 pos;
  static Vector2 dim;
};
