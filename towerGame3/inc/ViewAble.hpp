#pragma once
#include "Actor.hpp"
#include <string>
#include <unordered_map>
#include "SDL.h"

class ViewAble : public virtual Actor
{
public:
  static void SetRenderer(SDL_Renderer *renderer);
  static void SetView(class View *view);

  ViewAble(class Model &model, int col, int row);

  void Run();
  void SetTexture(const std::string &fileName);

  static SDL_Renderer *renderer;
  static class View *view;
  static std::unordered_map<std::string, SDL_Texture *> textures;

  SDL_Texture *texture = nullptr;
  int textureHeight = 0;
  int textureWidth = 0;
};
