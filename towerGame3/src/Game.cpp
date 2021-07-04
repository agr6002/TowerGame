#include "Config.hpp"
#include "Game.hpp"

using namespace Config::Game;

Game::Game()
    : controller(*this), model(*this), view(*this)
{
  if (Initialize())
  {
    Run();
  }
  Finalize();
}

void Game::Finalize()
{
  model.Finalize();
  controller.Finalize();
  view.Finalize();
}

bool Game::Initialize()
{
  if (!view.Initialize(WINDOW_DIM_X, WINDOW_DIM_Y))
  {
    return false;
  }
  controller.Initialize();
  model.Initialize(WINDOW_DIM_X, WINDOW_DIM_Y);
  return true;
}

void Game::Run()
{
  while (isRunning)
  {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timePrior + LOOP_TIME_MIN))
      ;
    Uint32 timeChange = SDL_GetTicks() - timePrior;
    if (timeChange > LOOP_TIME_MAX)
    {
      timeChange = LOOP_TIME_MAX;
    }
    controller.Run();
    model.Run(timeChange);
    view.Run();
    timePrior = SDL_GetTicks();
  }
}

void Game::StopGame()
{
  isRunning = false;
}
