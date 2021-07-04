#pragma once
#include "ViewAble.hpp"
//#include "Actor.hpp"

class Crop : public ViewAble, public virtual Actor
{
public:
  Crop(class Model &model, int col, int row);
};
