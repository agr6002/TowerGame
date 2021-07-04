#include <algorithm>
#include "Actor.hpp"
#include "Game.hpp"
#include "Model.hpp"
#include "Config.hpp"
#include "Bug.hpp"
#include "Crop.hpp"
#include "Tile.hpp"
#include "FlySwatter.hpp"
#include "ModelAble.hpp"
#include <iostream>

using namespace Config::Model;

Model::Model(Game &game)
    : game(game) {}

void Model::AddActor(Actor *actor)
{
  actors.emplace_back(actor);
}

void Model::AddModelAble(ModelAble *modelAble)
{
  modelAbles.emplace_back(modelAble);
}

void Model::Finalize() {}

void Model::Initialize(int worldWidth, int worldHeight)
{
  this->worldHeight = worldWidth;
  this->worldHeight = worldHeight;

  amount = 0;
  leftOver = 0;
  MSPerBug = 1700;
  numOfBugs = 0;
  bugsAreVisible = true;

  Actor::SetDim(worldWidth/NUM_OF_COL, worldHeight/NUM_OF_ROW);

  for (int i = 0; i < NUM_OF_ROW; i++)
  {
    for (int k = 0; k < NUM_OF_COL; k++)
    {
      AddActor(new Tile(*this, k, i, status[i][k]));
      switch (status[i][k])
      {
      case 0:
        grass.emplace_back(Vector2{k, i});
        break;
      case 1:
        path.emplace_back(Vector2{k, i});
        break;
      case 2:
        bugSpots.emplace_back(Vector2{k, i});
        break;
      case 3:
        cornSpots.emplace_back(Vector2{k, i});
        break;
      }
    }
  }
  AddActor(new FlySwatter(*this, 1, 2));
  for (auto vec: cornSpots)
  {
    AddActor(new Crop(*this, vec.x, vec.y));
  }

  ModelAble::SetModel(this);
  ModelAble::SetPath(path, bugSpots, cornSpots);
  startSpot = rand() % bugSpots.size();
  amountOfBugs = rand() % 10 + 3;
}

void Model::SetWorldSize(int width, int height)
{
 worldWidth = width;
 worldHeight = height; 
}

void Model::RemoveActor(Actor *actor)
{
  auto it = std::find(actors.begin(), actors.end(), actor);
  if (it != actors.end())
  {
    std::iter_swap(it, actors.end() - 1);
    actors.pop_back();
  }
}

void Model::RemoveModelAble(ModelAble *modelAble)
{
  auto it = std::find(modelAbles.begin(), modelAbles.end(), modelAble);
  if (it != modelAbles.end())
  {
    std::iter_swap(it, modelAbles.end() - 1);
    modelAbles.pop_back();
  }
}

void Model::Run(Uint32 timeChange)
{
  //std::cout << "Model running" << std::endl;
  amount = ((int)(timeChange) + leftOver) / MSPerBug;
  leftOver = (int)(timeChange) + leftOver - amount;
  if (leftOver > MSPerBug) {
    leftOver = 0;
  }
    if (numOfBugs == amountOfBugs)
  {
    numOfBugs = 0;
    bugsAreVisible = bugsAreVisible? false : true;
    if (bugsAreVisible) {
      amountOfBugs = rand() % 10 + 3;
    } else
    {
      amountOfBugs = rand() % 5;
    }
    startSpot = rand() % bugSpots.size();
  }
  for (int i = 0; i < amount; i++)
  {   
    if (bugsAreVisible)
    {
      AddActor(new Bug(*this, bugSpots.at(startSpot).x, bugSpots.at(startSpot).y));
    }
    numOfBugs += 1;
  }
  for (auto modelAble: modelAbles)
  {
    // std::cout << "FollowPath" << std::endl;
    modelAble->FollowPath();
    //modelAble->ChangePos(1, 0);
  }
}
