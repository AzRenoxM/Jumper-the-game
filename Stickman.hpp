#ifndef BLOCK_HPP
#define BLOCK_HPP

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>


class Stickman {
public:
   enum class State {
      IN_AIR,
      IN_RUN,
      IN_JUMP,
      IN_SQUAD,
      IN_STAND
   };

   enum class SpecState {
      STANDING_PLACE,
      SQUAT,
      JUMP_LEFT,
      JUMP_LEFT_PLACE,
      JUMP_RIGHT,
      JUMP_RIGHT_PLACE,
      JUMP_PLACE,
      RUN_LEFT,
      RUN_FROM_PLACE_LEFT,
      RUN_RIGHT,
      RUN_FROM_PLACE_RIGHT
   };ht_frames;

   Stickman(SDL_Renderer* renderer);

   static void createStandingPlaceFrames(SDL_Renderer* renderer);
   static void createSquatFrames(SDL_Renderer* renderer);
   static void createJumpLeftFrames(SDL_Renderer* renderer);
   static void createJumpLeftPlaceFrames(SDL_Renderer* renderer);
   static void createJumpRightFrames(SDL_Renderer* renderer);
   static void createJumpRightPlaceFrames(SDL_Renderer* renderer);
   static void createJumpPlaceFrames(SDL_Renderer* renderer);
   static void createRunLeftFrames(SDL_Renderer* renderer);
   static void createRunFromPlaceLeftFrames(SDL_Renderer* renderer);
   static void createRunRightFrames(SDL_Renderer* renderer);
   static void createRunFromPlaceRightFrames(SDL_Renderer* renderer);

   static std::vector<SDL_Texture*> standing_place_frames, squat_frames, jump_left_frames,
                                    jump_left_place_frames, jump_right_frames, jump_right_place_frames,
                                    jump_place_frames, run_left_frames, run_from_place_left_frames,
                                    run_right_frames, run_from_place_right_frames;

   constexpr static int standing_place_delay{100}, squat_delay{100}, jump_left_delay{100}, jump_left_place_delay{100},
                        jump_right_delay{100}, jump_right_place_delay{100}, jump_place_delay{100}, run_left_delay{100},
                        run_from_place_left_delay{100}, run_right_delay{100}, run_from_place_right_delay{100};
   
   constexpr static int standing_place_images_number{2}, squat_images_number{19}, jump_left_images_number{6}, jump_left_place_images_number{9},
                        jump_right_images_number{6}, jump_right_place_images_number{9}, jump_place_images_number{19}, run_left_images_number{15},
                        run_from_place_left_images_number{30}, run_right_images_number{15}, run_from_place_right_images_number{33};

   constexpr static int standing_place_index{0}, squat_index{0}, jump_left_index{0},
                        jump_left_place_index{0}, jump_right_index{0}, jump_right_place_index{0},
                        jump_place_index{0}, run_left_index{0}, run_from_place_left_index{0},
                        run_right_index{0}, run_from_place_right_index{0};

   State state_buffer;
   SpecState spec_state_buffer;
   int stickman_position_X, stickman_position_Y;
};

#endif
