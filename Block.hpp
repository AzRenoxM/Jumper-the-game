#ifndef BLOCK_HPP
#define BLOCK_HPP

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<iostream>
#include<cstdlib>
#include<string>

class Block{
public:
    SDL_Window* window_block;
    SDL_Renderer* renderer_block;
    SDL_Texture* temp_texture_block;
    int block_position_x_beg, block_position_x_fin, block_position_y;
    int lenght, height;

    SDL_Texture* create_texture();
    Block(SDL_Renderer* renderer_block, SDL_Window* window_block, int block_position_x_beg, int block_position_x_fin, int block_position_y);
    ~Block();
};

#endif