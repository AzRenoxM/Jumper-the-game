#include"World.hpp"

World::World(){
   // # SDL initiation
   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << "Sadly, the program cannot run. SDL Error: " << SDL_GetError() << std::endl;
      return -1;
   }
   // # creating a window
   this->window = SDL_CreateWindow("Jumper the game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->WINDOW_SIZE_X, this->WINDOW_SIZE_Y, SDL_WINDOW_SHOWN);
   if (window == nullptr) {
      std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
      SDL_Quit();
      return -1;
   }
   // # creating a renderer
   this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   if (renderer == nullptr) {
      std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
      SDL_DestroyWindow(window);
      SDL_Quit();
      return -1;
   }
}

World::~World(){
   delete this->window;
   delete this->renderer;
   window = nullptr;    
   renderer = nullptr;

   for(size_t i{0}; i < this->block_distribution.size(); i++){
      delete this->block_distribution[i];
      this->block_distribution[i] = nullptr;
   }
}

World::start(){
   // TODO functions to create:
      // TODO hard code map
      // TODO Footer
      // TODO score
      // TODO clock

}

// TODO function that create the world with the while loop inside

// TODO 
// TODO 
// TODO 
