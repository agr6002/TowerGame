#pragma once
#include "ViewAble.hpp"
#include "ModelAble.hpp"

class Bug : public ViewAble, public ModelAble, public virtual Actor
{
public:
  Bug(class Model &model, int col, int row);
};
