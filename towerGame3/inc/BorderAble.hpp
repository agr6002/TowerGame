#pragma once
#include "Actor.hpp"
#include "Vector2.hpp"

class BorderAble : public virtual Actor
{
public:
    static void SetNumOfColRow(int numOfCol, int numOfRow);
    static void SetPath(std::vector<Vector2> path, std::vector<Vector2> bugsSpots, 
        std::vector<Vector2> cornSpots);
    BorderAble(class Model &model, int col, int row);
    bool IsInVector(Vector2 part, std::vector<Vector2> vector);

    void Run();

private:
    static int numOfCol;
    static int numOfRow;
    static std::vector<Vector2> path;
    static std::vector<Vector2> cornSpots;
    static std::vector<Vector2> bugSpots;
    static std::vector<Vector2> grass;
};
