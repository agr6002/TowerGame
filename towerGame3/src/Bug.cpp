#include "Bug.hpp"
#include "Config.hpp"
#include "Actor.hpp"
#include "ViewAble.hpp"
#include "ModelAble.hpp"
using namespace Config::Actor::Bug;

Bug::Bug(class Model &model, int col, int row)
    : ModelAble(model, col, row), ViewAble(model, col, row), 
        Actor(model, col, row)
{
    SetTexture(IMAGE_FILE);
}
