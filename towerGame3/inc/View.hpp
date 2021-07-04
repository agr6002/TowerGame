#pragma once
//#include <string>
//#include <unordered_map>
#include <vector>
#include "SDL.h"

class View
{
public:
  View(class Game &game);

  void AddViewAble(class ViewAble *viewAble);
  void Finalize();
  bool Initialize(int windowWidth, int windowHeight);
  void RemoveViewAble(class ViewAble *viewAble);
  void Run();

private:
  class Game &game;
  int windowWidth;
  int windowHeight;
  SDL_Renderer *renderer;
  SDL_Window *window;
  
  std::vector<class ViewAble *> viewAbles;
};
