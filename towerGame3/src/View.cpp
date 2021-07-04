#include <algorithm>
#include "Config.hpp"
#include "Game.hpp"
#include "SDL_image.h"
#include <iostream>
#include "View.hpp"
#include "ViewAble.hpp"

using namespace Config::View;

View::View(Game &game)
    : game(game) {}

void View::AddViewAble(ViewAble *viewAble)
{
  //SDL_Log("BEFORE");
  viewAbles.emplace_back(viewAble);
  //SDL_Log("AFTER");
}

void View::Finalize()
{
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool View::Initialize(int windowWidth, int windowHeight)
{
  this->windowWidth = windowWidth;
  this->windowHeight = windowHeight;
  if (SDL_Init(INIT_SDL_FLAGS) != 0)
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow(TITLE, WINDOW_POS_X, WINDOW_POS_Y, windowWidth, windowHeight,
                            INIT_WINDOW_FLAGS);
  if (!window)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, INIT_RENDERER_INDEX,
                                INIT_RENDERER_FLAGS);
  if (!renderer)
  {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }

  if (IMG_Init(INIT_IMAGE_FLAGS) == 0)
  {
    SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
    return false;
  }

  ViewAble::SetRenderer(renderer);
  ViewAble::SetView(this);

  return true;
}

void View::RemoveViewAble(ViewAble *viewAble)
{
  auto it = std::find(viewAbles.begin(), viewAbles.end(), viewAble);
  if (it != viewAbles.end())
  {
    std::iter_swap(it, viewAbles.end() - 1);
    viewAbles.pop_back();
  }
}

void View::Run()
{
  //std::cout << "View running" << std::endl; 
  SDL_SetRenderDrawColor(renderer,
                         BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
  SDL_RenderClear(renderer);

  /* To test basic SDL drawing
  SDL_Rect rect1{100, 100, 100, 100};
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  SDL_RenderFillRect(renderer, &rect1);
  */

  for (auto viewAble : viewAbles)
  {
    viewAble->Run();
  }

  SDL_RenderPresent(renderer);
}
