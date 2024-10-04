#ifndef WORLD_HPP
#define WORLD_HPP

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include"Block.hpp"
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

class World{
private:
   bool exit_game;
   int FRAMES_NUMBER_BUFFER;
   int timer, score;
   int WINDOW_SIZE_X, WINDOW_SIZE_Y;
   SDL_Window* window;
   SDL_Renderer* renderer;
   SDL_Event e;

   std::vector<Block*> block_distribution;
   std::vector<SDL_Texture*> BackGround_frames; 
public:
   void start();
   void createLoad_hardCode_map_1();
   void create_backGround_frames();
   World(int WINDOW_SIZE_X = 800, int WINDOW_SIZE_Y = 800);
   ~World();
};
#endif
