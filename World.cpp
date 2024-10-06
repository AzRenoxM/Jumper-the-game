#include"Stickman.hpp"
#include"World.hpp"
#include"Block.hpp"

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

   // # Ground variables, blocks and function
   this->createLoad_hardCode_map_1();

   // # Backgroud frames and variables
   this->create_backGround_frames();
   const int delay_between_frames_backGround{300};
   int frame_index_backGround{0};
   Uint32 lastUpdateTime_backGround = SDL_GetTicks();

   // # Stickman
   Stickman* stickman = new Stickman(this->renderer);
   Uint32 lastUpdateTime_stickman = SDL_GetTicks();
   // ! add

   while(!this->exit_game){
      while(SDL_PollEvent(&e) != 0) {
         if(e.type == SDL_QUIT) {
            this->exit_game = true;
         }
         if(e.type == SDL_KEYDOWN){
            switch(e.key.keysym.sym){
               case SDLK_w:
                  printf("W key pressed\n");
                  stickman->stickman_position_Y -= 8;
                  break;
               case SDLK_a:
                  printf("A key pressed\n");
                  stickman->stickman_position_X -= 8;
                  break;
               case SDLK_s:
                  printf("S key pressed\n");
                  stickman->stickman_position_Y += 8;
                  break;
               case SDLK_d:
                  printf("D key pressed\n");
                  stickman->stickman_position_X += 8;
                  break;
            }
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

      // # Blocks implementation 
      for(int i{0}; i < this->block_distribution.size(); i++){
         SDL_Rect temp_rect_block = {this->block_distribution[i]->block_position_x_beg, this->block_distribution[i]->block_position_y, this->block_distribution[i]->lenght, this->block_distribution[i]->height};
         SDL_RenderCopy(this->renderer, this->block_distribution[i]->temp_texture_block, nullptr, &temp_rect_block);
      }
      
      // // # standing implementation
      // if(current_time - lastUpdateTime_standing >= delay_between_frames_standing){
      //    lastUpdateTime_standing = current_time;
      //    frame_index_standing = (frame_index_standing + 1) % this->standing_frames.size();
      // }
      // // ! image resolution 500x350
      // SDL_Rect temp_rect_standing = {stickman_position_X, stickman_position_Y, 500, 350};
      // SDL_RenderCopy(this->renderer, this->standing_frames[frame_index_standing], nullptr, &temp_rect_standing);

      switch(stickman->spec_state_buffer){
         case stickman->SpecState::STANDING_PLACE:
            if(current_time - lastUpdateTime_stickman >= stickman->standing_place_delay){
               lastUpdateTime_stickman = current_time;
               Stickman::standing_place_index = (Stickman::standing_place_index + 1) % Stickman::standing_place_images_number.size();

               SDL_Rect temp_rect_standing = {stickman->stickman_position_X, stickman->stickman_position_Y, 500, 350};
               SDL_RenderCopy(this->renderer, Stickman::standing_place_frames[Stickman::standing_place_index], nullptr, &temp_rect_standing);
            }
            break;
         case stickman->SpecState::SQUAT:
            
            break;
         case stickman->SpecState::JUMP_LEFT:
            
            break;
         case stickman->SpecState::JUMP_LEFT_PLACE:
            
            break;
         case stickman->SpecState::JUMP_RIGHT:
            
            break;
         case stickman->SpecState::JUMP_RIGHT_PLACE:
            
            break;
         case stickman->SpecState::JUMP_PLACE:
            
            break;
         case stickman->SpecState::RUN_LEFT:
            
            break;
         case stickman->SpecState::RUN_FROM_PLACE_LEFT:
            
            break;
         case stickman->SpecState::RUN_RIGHT:
            
            break;
         case stickman->SpecState::RUN_FROM_PLACE_RIGHT:
            
            break;
      }

      SDL_RenderPresent(this->renderer);
   }
}


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
   Block* ground = new Block(this->renderer, this->window, 0, 800, 730);
   this->block_distribution.push_back(ground);

   Block* platform_1 = new Block(this->renderer, this->window, 380, 520, 100);
   this->block_distribution.push_back(platform_1);

   Block* platform_2 = new Block(this->renderer, this->window, 200, 300, 650);
   this->block_distribution.push_back(platform_2);

   Block* platform_3 = new Block(this->renderer, this->window, 400, 500, 600);
   this->block_distribution.push_back(platform_3);

   Block* platform_4 = new Block(this->renderer, this->window, 550, 650, 550);
   this->block_distribution.push_back(platform_4);

   Block* platform_5 = new Block(this->renderer, this->window, 100, 200, 500);
   this->block_distribution.push_back(platform_5);

   Block* platform_6 = new Block(this->renderer, this->window, 300, 450, 450);
   this->block_distribution.push_back(platform_6);

   Block* platform_7 = new Block(this->renderer, this->window, 600, 750, 400);
   this->block_distribution.push_back(platform_7);

   Block* platform_8 = new Block(this->renderer, this->window, 50, 180, 350);
   this->block_distribution.push_back(platform_8);

   Block* platform_9 = new Block(this->renderer, this->window, 250, 370, 300);
   this->block_distribution.push_back(platform_9);

   Block* platform_10 = new Block(this->renderer, this->window, 450, 600, 250);
   this->block_distribution.push_back(platform_10);

   Block* platform_11 = new Block(this->renderer, this->window, 700, 800, 200);
   this->block_distribution.push_back(platform_11);

   Block* platform_12 = new Block(this->renderer, this->window, 100, 250, 150);
   this->block_distribution.push_back(platform_12);
}

// TODO Footer
// TODO score
// TODO clock