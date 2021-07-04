#pragma once
#include "ViewAble.hpp"

class Tile : public ViewAble, public virtual Actor
{
public:

  Tile(class Model &model, int col, int row, int type);

  int type;
};