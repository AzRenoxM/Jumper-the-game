#include"Stickman.hpp"

Stickman::Stickman(SDL_Renderer* renderer) : state_buffer(State::IN_STAND), spec_state_buffer(SpecState::STANDING_PLACE), stickman_position_X(150), stickman_position_Y(430){
   Stickman::createStandingPlaceFrames(renderer);
   Stickman::createSquatFrames(renderer);
   Stickman::createJumpLeftFrames(renderer);
   Stickman::createJumpLeftPlaceFrames(renderer);
   Stickman::createJumpRightFrames(renderer);
   Stickman::createJumpRightPlaceFrames(renderer);
   Stickman::createJumpPlaceFrames(renderer);
   Stickman::createRunLeftFrames(renderer);
   Stickman::createRunFromPlaceLeftFrames(renderer);
   Stickman::createRunRightFrames(renderer);
   Stickman::createRunFromPlaceRightFrames(renderer);
}

void Stickman::createStandingPlaceFrames(SDL_Renderer* renderer){
   for(int i{0}; i < Stickman::standing_place_images_number; i++){
      SDL_Surface* temp_standing_sur;
      if(i == 0){
         temp_standing_sur = IMG_Load("StickMan_graph/Standing_place/standing_left.png");
      } else {
         temp_standing_sur = IMG_Load("StickMan_graph/Standing_place/standing_right.png");
      }
      if(!temp_standing_sur){
         std::cerr << "Unable to load image " << "StickMan_graph/Standing_place/standing_left.png or StickMan_graph/Standing_place/standing_right.png" << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* standing_texture = SDL_CreateTextureFromSurface(renderer, temp_standing_sur);
      if(standing_texture){
         Stickman::standing_place_frames.push_back(standing_texture);
      }
      SDL_FreeSurface(temp_standing_sur);
   }
   if(Stickman::standing_place_frames.empty()) {
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createSquatFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::squat_images_number; ++i){ 
      if(i < 10){
         path = "StickMan_graph/Squat/squat00" + std::to_string(i) + ".png";
      } else {
         path = "StickMan_graph/Squat/squat0" + std::to_string(i) + ".png"; 
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::squat_frames.push_back(temp_tex);  
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::squat_frames.empty()){ 
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createJumpLeftFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::jump_left_images_number; ++i){ 
      if(i < 10){
         path = "StickMan_graph/Jump_left/Jump_left00" + std::to_string(i) + ".png"; 
      } else {
         path = "StickMan_graph/Jump_left/Jump_left0" + std::to_string(i) + ".png";
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::jump_left_frames.push_back(temp_tex); 
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::jump_left_frames.empty()){ 
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createJumpLeftPlaceFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::jump_left_place_images_number; ++i){ // ! change
      if(i < 10){
         path = "StickMan_graph/Jump_left_place/Jump_left_place00" + std::to_string(i) + ".png"; // ! change
      } else {
         path = "StickMan_graph/Jump_left_place/Jump_left_place0" + std::to_string(i) + ".png"; // ! change
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::jump_left_place_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::jump_left_place_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createJumpRightFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::jump_right_images_number; ++i){ // ! change
      if(i < 10){
         path = "StickMan_graph/Jump_right/Jump_right00" + std::to_string(i) + ".png"; // ! change
      } else {
         path = "StickMan_graph/Jump_right/Jump_right0" + std::to_string(i) + ".png"; // ! change
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::jump_right_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::jump_right_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createJumpRightPlaceFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::jump_right_place_images_number; ++i){ // ! change
      if(i < 10){
         path = "StickMan_graph/Jump_right_place/Jump_right_place00" + std::to_string(i) + ".png"; // ! change
      } else {
         path = "StickMan_graph/Jump_right_place/Jump_right_place0" + std::to_string(i) + ".png"; // ! change
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::jump_right_place_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::jump_right_place_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createJumpPlaceFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::jump_place_images_number; ++i){ // ! change
      if(i < 10){
         path = "StickMan_graph/Jump_place/Jump_place00" + std::to_string(i) + ".png"; // ! change
      } else {
         path = "StickMan_graph/Jump_place/Jump_place0" + std::to_string(i) + ".png"; // ! change
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::jump_place_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::jump_place_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createRunLeftFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::run_left_images_number; ++i){ // ! change
      path = "StickMan_graph/StickMan_run_left/run_left00" + std::to_string(i) + ".png"; // ! change
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::run_left_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::run_left_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createRunFromPlaceLeftFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::run_from_place_left_images_number; ++i){ // ! change
      if(i < 10){
         path = "StickMan_graph/StickMan_run_from_place_left/run_from_place_left00" + std::to_string(i) + ".png"; // ! change
      } else {
         path = "StickMan_graph/StickMan_run_from_place_left/run_from_place_left0" + std::to_string(i) + ".png"; // ! change
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::run_from_place_left_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::run_from_place_left_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createRunRightFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::run_right_images_number; ++i){ // ! change
      path = "StickMan_graph/StickMan_run_right/run_right00" + std::to_string(i) + ".png"; // ! change
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::run_right_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::run_right_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}

void Stickman::createRunFromPlaceRightFrames(SDL_Renderer* renderer){
   std::string path;
   for(size_t i{1}; i <= Stickman::run_from_place_right_images_number; ++i){ // ! change
      if(i < 10){
         path = "StickMan_graph/StickMan_run_from_place_right/run_from_place_right00" + std::to_string(i) + ".png"; // ! change
      } else {
         path = "StickMan_graph/StickMan_run_from_place_right/run_from_place_right0" + std::to_string(i) + ".png"; // ! change
      }
      SDL_Surface* temp_sur = IMG_Load(path.c_str());
      if(!temp_sur){
         std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
         continue;
      }
      SDL_Texture* temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
      if(temp_tex){
         Stickman::run_from_place_right_frames.push_back(temp_tex);  // ! change
      }
      SDL_FreeSurface(temp_sur);
   }
   if (Stickman::run_from_place_right_frames.empty()){  // ! change
      std::cerr << "No frames loaded! Exiting..." << std::endl;
      IMG_Quit();
      SDL_Quit();
      exit(EXIT_FAILURE);
   }
}


