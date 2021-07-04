#include "Config.hpp"
#include "SDL_image.h"

namespace Config
{
  namespace Actor
  {
    namespace Bug
    {
      char const *
          IMAGE_FILE =
              "assets/images/fly.png";
    }
    namespace Crop
    {
      char const *
          IMAGE_FILE =
              "assets/images/crops.png";
    }
    namespace FlySwatter
    {
      char const *
          IMAGE_FILE =
              "assets/images/flySwatter.png";
    }
    namespace Tile
    {
      char const *
          IMAGE_FILE0 =
              "assets/images/grass.png";
      char const *
          IMAGE_FILE1 =
              "assets/images/sand.png";
      char const *
          IMAGE_FILE2 =
              "assets/images/enemyBase.jpg";
      char const *
          IMAGE_FILE3 =
              "assets/images/playerBase.jpg";
    }
  }

  namespace Controller
  {
    Uint8 const
        STOP_GAME =
            SDL_SCANCODE_ESCAPE;
  }

  namespace Game
  {
    Uint32 const // milliseconds
        LOOP_TIME_MAX =
            50;
    Uint32 const // milliseconds
        LOOP_TIME_MIN =
            16;
    int const
        WINDOW_DIM_X =
            1024;
    int const
        WINDOW_DIM_Y =
            700;
  }

  namespace Model
  {
    int const 
        NUM_OF_COL = 
            10;
    int const 
        NUM_OF_ROW =
            10;
  }

  namespace View
  {
    Color const
        BG_COLOR =
            {25, 255, 125, 255};
    int const
        INIT_IMAGE_FLAGS =
            IMG_INIT_PNG;
    Uint32 const
        INIT_RENDERER_FLAGS =
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    int const
        INIT_RENDERER_INDEX =
            -1;
    Uint32 const
        INIT_SDL_FLAGS =
            SDL_INIT_VIDEO | SDL_INIT_AUDIO;
    Uint32 const
        INIT_WINDOW_FLAGS =
            0;
    char const *
        TITLE =
            "Title";
    int const
        WINDOW_POS_X =
            SDL_WINDOWPOS_CENTERED;
    int const
        WINDOW_POS_Y =
            SDL_WINDOWPOS_CENTERED;
  }
}
