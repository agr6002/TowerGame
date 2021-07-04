#include "FlySwatter.hpp"
#include "Config.hpp"
#include "Actor.hpp"
#include "ViewAble.hpp"
#include "ControllerAble.hpp"
using namespace Config::Actor::FlySwatter;

FlySwatter::FlySwatter(class Model &model, int col, int row)
   : ViewAble(model, col, row), ControllerAble(model, col, row), Actor(model, col, row)
{
    SetTexture(IMAGE_FILE);
}
