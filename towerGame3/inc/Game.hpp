#pragma once
#include "Controller.hpp"
#include "Model.hpp"
#include "SDL.h"
#include "Actor.hpp"
#include "View.hpp"

class Game
{
public:
  Game();

  void Finalize();
  bool Initialize();
  void Run();
  void StopGame();

private:
  Controller controller;
  Model model;
  View view;

  bool isRunning = true;
  Uint32 timePrior = 0;
};
