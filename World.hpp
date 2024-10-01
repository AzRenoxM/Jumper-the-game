#ifndef WORLD_HPP
#define WORLD_HPP

#include<SDL/SDL2.h>
#include"Block.hpp"
#include<iostream>
#include<vector>

class World{
private:
   int timer, score;
   int WINDOW_SIZE_X, WINDOW_SIZE_Y;
   std::vector<Block*> block_distribution;
   SDL_Window* window;
   SDL_Renderer* renderer;

   start();
   World();
   ~World();
};
#endif
