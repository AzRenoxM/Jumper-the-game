#include"Block.hpp"

Block::Block(SDL_Renderer* renderer, SDL_Window* window, int block_position_x_beg, int block_position_x_fin, int block_position_y)
	: block_position_x_beg(block_position_x_beg), block_position_x_fin(block_position_x_fin), block_position_y(block_position_y) {
		window_block = window;
		renderer_block = renderer;
		this->create_texture();
	}

Block::create_texture(){
	SDL_Surface* temp_surface_block = IMG_Load("") // ! add image
	this->temp_texture = SDL_CreateTextureFromSurface(this->renderer_block, temp_surface_block);
	if(temp_texture == nullptr){
		SDL_FreeSurface(temp_surface_block);
		std::cout << "Cannot create a texture of the block" << std::endl;
		return -1;
	}  
	SDL_FreeSurface(temp_surface_block);
}

Block::~Block(){
	delete this->window_block;
	delete this->renderer_block;
	delete this->temp_texture_block;
	window_block = nullptr;	
	renderer_block = nullptr;
	temp_texture_block = nullptr;
}
