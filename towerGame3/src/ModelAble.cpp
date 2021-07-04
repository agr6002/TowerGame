#include "Actor.hpp"
#include "Model.hpp"
#include "ModelAble.hpp"
#include <iostream>
#include  <cstdlib>

Model *ModelAble::model = nullptr;
std::vector<Vector2> ModelAble::path;
std::vector<Vector2> ModelAble::cornSpots;

void ModelAble::SetModel(Model *model)
{
    ModelAble::model = model;
}

void ModelAble::SetPath(std::vector<Vector2> path, std::vector<Vector2> bugsSpots, std::vector<Vector2> cornSpots)
{
    path.insert(path.end(), bugsSpots.begin(), bugsSpots.end());
    path.insert(path.end(), cornSpots.begin(), cornSpots.end());
    ModelAble::path = path;
    ModelAble::cornSpots = cornSpots;
}

ModelAble::ModelAble(class Model &model, int col, int row)
  : Actor(model, col, row)
{
    model.AddModelAble(this);
    lastRowCol = Vector2{col, row};
}

void ModelAble::ChangePos(float dx, float dy)
{
    SetPos(GetPosX() + dx, GetPosY() + dy);
}

// void ModelAble::ChangeRowCol(int col, int row, std::string path)
// {
//     if (col > 0 && col < )
// }

void ModelAble::FollowPath()
{ 
    // std::cout << (double)GetPosX()/GetDimX() << " - " <<  (GetPosY() + 0.0) /GetDimY() << std::endl;
    // std::cout << GetPosX() << " : " << GetDimX() << std::endl;
    // std::cout << GetPosY() << " : " << GetDimY() << std::endl;
    if (
        (double)GetPosX()/GetDimX() 
            ==  
        (int)(GetPosX()/GetDimX()) + 0.5
                && 
        (double)GetPosY()/GetDimY()
            ==  
        (int)(GetPosY()/GetDimY()) + 0.5
    )
    {
        NextMove();
        //std::cout << "double" << std::endl;
    }
    ChangePos(change.x, change.y);  
}

void ModelAble::NextMove()
{
    int numOfPosiblities{};
    numOfPosiblities = 0;
    std::vector< Vector2 > posiblities;
    int col = (int)(GetPosX()/GetDimX());
    int row = (int)(GetPosY()/GetDimY());
    if (IsInVector(Vector2{col - 1, row}, path) && col - 1 != lastRowCol.x)
    {
        numOfPosiblities += 1;
        posiblities.emplace_back(Vector2{-1, 0});
    } 
    if (IsInVector(Vector2{col + 1, row}, path) && col + 1 != lastRowCol.x)
    {
        numOfPosiblities += 1;
        posiblities.emplace_back(Vector2{1, 0});
    }
    if (IsInVector(Vector2{col, row - 1}, path) && row - 1 != lastRowCol.y)
    {
        numOfPosiblities += 1;
        posiblities.emplace_back(Vector2{0, -1});
    }
     if (IsInVector(Vector2{col, row + 1}, path) && row + 1 != lastRowCol.y)
    {
        numOfPosiblities += 1;
        posiblities.emplace_back(Vector2{0, 1});
    }
    if (numOfPosiblities == 1)
    {
       change = posiblities.at(0);
    } else if(numOfPosiblities > 1)
    {
        int num = rand() % numOfPosiblities;   
        //std::cout << num << std::endl;
        change = posiblities.at(num);
    }else 
    {
        change = {0, 0};
    }
    if (change.x != 0 || change.y != 0)
    {
        if (IsInVector(Vector2{col, row}, cornSpots))
        {
            change = {0, 0};
        } else 
        {
            lastRowCol = Vector2{col, row};
        }
    }
}

bool ModelAble::IsInVector(Vector2 part, std::vector<Vector2> vectors)
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
