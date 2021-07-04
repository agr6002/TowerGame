#include "Crop.hpp"
#include "Config.hpp"
using namespace Config::Actor::Crop;

Crop::Crop(class Model &model, int col, int row)
    : ViewAble(model, col, row), Actor(model, col, row)
{
    SetTexture(IMAGE_FILE);
}
