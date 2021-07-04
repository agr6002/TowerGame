#pragma once
#include "Color.hpp"
#include "SDL.h"

namespace Config
{
  namespace Actor
  {
    namespace Bug
    {
      extern char const *IMAGE_FILE;
      extern float const DIM_X;
      extern float const DIM_Y;
    }
    namespace Crop
    {
      extern char const *IMAGE_FILE;
      extern float const DIM_X;
      extern float const DIM_Y;
    }
    namespace FlySwatter
    {
      extern char const *IMAGE_FILE;
      extern float const DIM_X;
      extern float const DIM_Y;
    }
    namespace Tile
    {
      extern char const *IMAGE_FILE0;
      extern char const *IMAGE_FILE1;
      extern char const *IMAGE_FILE2;
      extern char const *IMAGE_FILE3;
    }
  }

  namespace Controller
  {
    extern Uint8 const STOP_GAME;
  }

  namespace Game
  {
    extern Uint32 const LOOP_TIME_MAX;
    extern Uint32 const LOOP_TIME_MIN;
    extern int const WINDOW_DIM_X;
    extern int const WINDOW_DIM_Y;
  }

  namespace Model 
  {
    extern int const NUM_OF_COL;
    extern int const NUM_OF_ROW;
  }

  namespace View
  {
    extern Color const BG_COLOR;
    extern int const INIT_IMAGE_FLAGS;
    extern Uint32 const INIT_RENDERER_FLAGS;
    extern int const INIT_RENDERER_INDEX;
    extern Uint32 const INIT_SDL_FLAGS;
    extern Uint32 const INIT_WINDOW_FLAGS;
    extern char const *TITLE;
    extern int const WINDOW_POS_X;
    extern int const WINDOW_POS_Y;
  }
}
