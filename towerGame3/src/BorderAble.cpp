#include "Actor.hpp"
#include "BorderAble.hpp"
#include <iostream>
#include  <cstdlib>

int BorderAble::numOfCol;
int BorderAble::numOfRow;
std::vector<Vector2> BorderAble::path;
std::vector<Vector2> BorderAble::cornSpots;
std::vector<Vector2> BorderAble::bugSpots;
std::vector<Vector2> BorderAble::grass;

void BorderAble::SetNumOfColRow(int numOfCol, int numOfRow)
{
    BorderAble::numOfCol = numOfCol;
    BorderAble::numOfRow = numOfRow;
}

void BorderAble::SetPath(std::vector<Vector2> path, std::vector<Vector2> bugsSpots, std::vector<Vector2> cornSpots)
{
    BorderAble::path = path;
    BorderAble::bugSpots = bugSpots;
    BorderAble::cornSpots = cornSpots;
    // for (int i = 0; i < numOfCol; i++) 
    // {
    //     for (int j = 0; j < numOfRow; j++)
    //     {
    //         if ( !IsInVector(Vector2{i, j}, BorderAble::path) 
    //             && !IsInVector(Vector2{i, j}, BorderAble::bugSpots)
    //             && !IsInVector(Vector2{i, j}, BorderAble::cornSpots)) 
    //         {
    //             grass.emplace_back();
    //         }
    //     }
    // }
}

BorderAble::BorderAble(class Model &model, int col, int row)
  : Actor(model, col, row)
{}

void BorderAble::Run()
{}

bool BorderAble::IsInVector(Vector2 part, std::vector<Vector2> vectors)
{
    for (auto part2: vectors)
    {
        if (part2.x == part.x && part2.y == part.y)
        {
            // std::cout << "true";
            return true;
        }
    }
    // std::cout << "false";
    return false;
}
