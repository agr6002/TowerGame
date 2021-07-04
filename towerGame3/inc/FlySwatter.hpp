#pragma once
#include "ViewAble.hpp"
#include "ControllerAble.hpp"

class FlySwatter : public ViewAble, public ControllerAble, public virtual Actor
{
public:
    FlySwatter(class Model &model, int col, int row);
};
