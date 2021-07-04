#pragma once
#include <vector>

class Controller
{
public:
  Controller(class Game &game);

  void AddControllerAble(class ControllerAble *controllerAble);
  void Finalize();
  void Initialize();
  void RemoveControllerAble(class ControllerAble *controllerAble);
  void Run();

private:
  class Game &game;
  std::vector<class ControllerAble *> controllerAbles;
  int amount;
  int numTimes;
};
