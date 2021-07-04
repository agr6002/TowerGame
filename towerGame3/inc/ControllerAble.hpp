#pragma once
#include "Actor.hpp"
//#include "BorderAble.hpp"
#include "Vector2.hpp"

class ControllerAble : public virtual Actor
{
public:
  static void SetController(class Controller *controller);

  ControllerAble(class Model &model, int col, int row);

  void Run();

private:
  static class Controller *controller;
  Vector2 rowCol{0, 0};
};
