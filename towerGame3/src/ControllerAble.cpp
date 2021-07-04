#include "Actor.hpp"
#include "Controller.hpp"
#include "ControllerAble.hpp"
#include "SDL.h"
#include <iostream>

Controller *ControllerAble::controller = nullptr;

void ControllerAble::SetController(Controller *controller)
{
  ControllerAble::controller = controller;
}

ControllerAble::ControllerAble(class Model &model, int col, int row)
  : Actor(model, col, row)
{
  controller->AddControllerAble(this);
}

void ControllerAble::Run()
{
  rowCol= {(int)GetPosX()/GetDimX(),(int)GetPosY()/GetDimY()};
  // std::cout << (GetPosX()/GetDimX()) << " : " << (GetPosY()/GetDimX()) << std::endl;
  const Uint8 *keyState = SDL_GetKeyboardState(NULL);
  if (keyState[SDL_SCANCODE_W] || keyState[SDL_SCANCODE_UP]) 
  {
    if (rowCol.y - 1 > -1)
    {
      SetRowCol(rowCol.x, rowCol.y - 1);
    }
    std::cout << "up" << std::endl;
  } else if (keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_LEFT]) 
  {
    if (rowCol.x - 1 > -1)
    {
      SetRowCol(rowCol.x - 1, rowCol.y);
    }
    std::cout << "left" << std::endl;
  } else if (keyState[SDL_SCANCODE_S] || keyState[SDL_SCANCODE_DOWN])
  {
    if (rowCol.y + 1 < 14)
    {
      SetRowCol(rowCol.x, rowCol.y + 1);
    }
    std::cout << "down" << std::endl;
  } else if (keyState[SDL_SCANCODE_D] || keyState[SDL_SCANCODE_RIGHT])
  {
    // std::cout << "---------------" << std::endl;
    // std::cout << GetPosX() << " : " << GetPosY() << std::endl;
    if (rowCol.x + 1 < 14)
    {
      SetRowCol(rowCol.x + 1, rowCol.y);
    }
    std::cout << "right" << std::endl;
    //std::cout << GetPosX() << " : " << GetPosY() << std::endl;
  }
  rowCol= {(int)(GetPosX()/GetDimX()),(int)(GetPosY()/GetDimY())};
  //std::cout << (GetPosX()/GetDimX()) << " : " << (GetPosY()/GetDimX()) << std::endl;
}
