#include <algorithm>
#include "Actor.hpp"
#include "Model.hpp"

Vector2 Actor::dim = Vector2{100, 100};

void Actor::SetDim(int dimX, int dimY)
{
  dim.x = dimX;
  dim.y = dimY;
}

Actor::Actor(Model &model, int col, int row)
    : model(model), pos((col + 0.5) * dim.x, (row + 0.5) * dim.y)
{
  model.AddActor(this);
}

Actor::~Actor()
{
  model.RemoveActor(this);
}

Model Actor::GetModel()
{
  return model;
}

void Actor::SetPos(float posX, float posY)
{
  pos.x = posX;
  pos.y = posY;
}

void Actor::SetRowCol(int col, int row)
{
  pos.x = (col + 0.5) * dim.x;
  pos.y = (row + 0.5) * dim.y;
}
