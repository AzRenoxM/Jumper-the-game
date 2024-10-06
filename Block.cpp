#include"Block.hpp"


Block::Block(SDL_Renderer* renderer_block, SDL_Window* window_block, int block_position_x_beg, int block_position_x_fin, int block_position_y)
	: renderer_block(renderer_block), window_block(window_block), block_position_x_beg(block_position_x_beg), block_position_x_fin(block_position_x_fin), block_position_y(block_position_y) {
		this->lenght = this->block_position_x_fin - this->block_position_x_beg;
		this->height = 14; // ! image pixels
		this->create_texture();
	}

SDL_Texture* Block::create_texture(){
	SDL_Surface* temp_surface_block = IMG_Load("StickMan_graph/barra/Barra_test.png"); 
	if(temp_surface_block == nullptr){
		std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE);
   }
	this->temp_texture_block = SDL_CreateTextureFromSurface(this->renderer_block, temp_surface_block);
	if(temp_texture_block == nullptr){
		SDL_FreeSurface(temp_surface_block);
		std::cout << "Cannot create a texture of the block: " << SDL_GetError() << std::endl;
      exit(EXIT_FAILURE);
	}  
	SDL_FreeSurface(temp_surface_block);
	return temp_texture_block;
}

Block::~Block() {
    if(this->temp_texture_block){
        SDL_DestroyTexture(this->temp_texture_block);
    }
}
