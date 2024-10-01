#ifndef BLOCK_HPP
#define BLOCK_HPP

#include<SDL/SDL2.h>
#include<iostream>

class Block{
private:
    int block_position_x_beg, block_position_x_fin, block_position_y;
    SDL_Window* window_block;
    SDL_Renderer* renderer_block;
    SDL_Texture* temp_texture_block;

    SDL_Texture* create_texture();
    Block(SDL_Renderer* renderer, SDL_Window* window, int block_position_x_beg, int block_position_x_fin, int block_position_y);
    ~Block();
};

#endif