#include "Tile.hpp"
#include "Config.hpp"
#include "Actor.hpp"
#include "ViewAble.hpp"
using namespace Config::Actor::Tile;

Tile::Tile(class Model &model, int col, int row, int type)
    : ViewAble(model, col, row), 
            Actor(model, col, row), 
            type(type)
    //: Actor(model, DIM_X * col + DIM_X/2, DIM_Y * row + DIM_Y/2, DIM_X, DIM_Y), type(type)
{
    switch (type)
    {
    case 0:
        SetTexture(IMAGE_FILE0);
        break;
    
    case 1:
        SetTexture(IMAGE_FILE1);
        break;
    
    case 2:
        SetTexture(IMAGE_FILE2);
        break;
    
    case 3:
        SetTexture(IMAGE_FILE3);
        break;
    }
}
