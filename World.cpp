#include"World.hpp"

World::World(int WINDOW_SIZE_X, int WINDOW_SIZE_Y)
   : WINDOW_SIZE_X(WINDOW_SIZE_X), WINDOW_SIZE_Y(WINDOW_SIZE_Y) {
   // # SDL initiation
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << "Sadly, the program cannot run. SDL Error: " << SDL_GetError() << std::endl;
      exit(EXIT_FAILURE);
   }
   // # SDL_Image initiation
   if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
      std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
      SDL_Quit();
      exit(EXIT_FAILURE);;
   }
   // # creating a window
   this->window = SDL_CreateWindow("Jumper the game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->WINDOW_SIZE_X, this->WINDOW_SIZE_Y, SDL_WINDOW_SHOWN);
   if(window == nullptr) {
      std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
   // # creating a renderer
   this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
   if(renderer == nullptr) {
      std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
      SDL_DestroyWindow(this->window);
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

World::~World(){
   for(size_t i{0}; i < this->block_distribution.size(); i++){
      delete this->block_distribution[i];
      this->block_distribution[i] = nullptr;
   }
   SDL_DestroyRenderer(this->renderer);
   SDL_DestroyWindow(this->window);
   SDL_Quit();
}

void World::start(){
   // # General variables
   this->exit_game = false;

   // # Backgroud frames and variables
   this->create_backGround_frames();
   const int delay_between_frames_backGround{300};
   int frame_index_backGround{0};
   Uint32 lastUpdateTime_backGround = SDL_GetTicks();

   while(!this->exit_game) {
      while(SDL_PollEvent(&e) != 0) {
         if(e.type == SDL_QUIT) {
            this->exit_game = true;
         }
      }
      // # background implementation
      Uint32 current_time = SDL_GetTicks();
      if(current_time - lastUpdateTime_backGround >= delay_between_frames_backGround){
         lastUpdateTime_backGround = current_time;
         frame_index_backGround = (frame_index_backGround + 1) % this->BackGround_frames.size();
      }
      SDL_RenderClear(this->renderer);
      SDL_RenderCopy(this->renderer, this->BackGround_frames[frame_index_backGround], nullptr, nullptr);

      SDL_Rect ground = {this->block_distribution[0]->block_position_x_beg, this->block_distribution[0]->block_position_y, this->block_distribution[0]->lenght, this->block_distribution[0]->height};
      SDL_RenderCopy(this->renderer, this->block_distribution[0]->temp_texture_block, nullptr, &ground);

      SDL_RenderPresent(this->renderer);
   }
}

// TODO passing through frames + time managment SDL 
// TODO a little GUI
   // TODO cutting images with python
// TODO hard coded map <-


// TODO Footer
// TODO score
// TODO clock

void World::create_backGround_frames(){
   this->FRAMES_NUMBER_BUFFER = 65;
   std::string path;
   for(size_t i{1}; i <= this->FRAMES_NUMBER_BUFFER; ++i){
      if(i < 10){
         path = "StickMan_graph/BackGround/BackGround00" + std::to_string(i) + ".png";
      } else {
         path = "StickMan_graph/BackGround/BackGround0" + std::to_string(i) + ".png";
      }
      SDL_Surface* temp_background_sur = IMG_Load(path.c_str());
      if(!temp_background_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_background_tex = SDL_CreateTextureFromSurface(this->renderer, temp_background_sur);
      if(temp_background_tex){
         this->BackGround_frames.push_back(temp_background_tex);
      }
      SDL_FreeSurface(temp_background_sur);
   }
   if (this->BackGround_frames.empty()) {
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void World::createLoad_hardCode_map_1(){
   Block* ground = new Block(this->renderer, this->window, 0, 800, 700);
   this->block_distribution.push_back(ground);
}
