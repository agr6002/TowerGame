#pragma once
#include "SDL.h"
#include "Config.hpp"
#include <vector>

using namespace Config::Model;

class Model
{
public:
  Model(class Game &game);

  void AddActor(class Actor *actor);
  void AddModelAble(class ModelAble *modelAble);
  void Finalize();
  void Initialize(int worldWidth, int worldHeight);
  void SetWorldSize(int width, int height);
  void RemoveActor(class Actor *actor);
  void RemoveModelAble(class ModelAble *modelAble);
  void Run(Uint32 timeChange);

private:
  class Game &game;
  std::vector<class Vector2> cornSpots;
  std::vector<class Vector2> path;
  std::vector<class Vector2> bugSpots;
  std::vector<class Vector2> grass;
  std::vector<class Actor *> actors;
  std::vector<class ModelAble *> modelAbles;
  int leftOver;
  int amount;
  int MSPerBug;
  int worldWidth;
  int worldHeight;
  int startSpot;  
  int amountOfBugs;
  int numOfBugs; 
  bool bugsAreVisible;

  int status[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 2, 1, 0, 0, 0, 0, 0, 3, 3},
    {0, 0, 0, 0, 1, 1, 1, 1, 3, 3},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 2, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
};
