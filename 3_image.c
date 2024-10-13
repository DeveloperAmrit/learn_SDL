#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

SDL_Texture* imageTextureFromPath(SDL_Renderer* renderer,const char* path);

const int width = 600;
const int height = 400;

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window1 = SDL_CreateWindow("Home", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// (1) Initiate the image library
	IMG_Init(IMG_INIT_JPG | IMG_INIT_WEBP | IMG_INIT_PNG);

	// (2) Make image texture using imageTextureFromPath
	SDL_Texture* image_texture = imageTextureFromPath(renderer1,"C:/Users/Hp/Pictures/Amrit/ada_1.webp");

	// (3) set position and size
	// can get the original dimensions like this
	int image_width, image_height;
	SDL_QueryTexture(image_texture, NULL, NULL, &image_width, &image_height);
	// i am not giving original params
	SDL_Rect textureDestination = {0,0,100,200};

	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
		SDL_RenderClear(renderer1);
		
		// (4) use SDL_RenderCopy function
		SDL_RenderCopy(renderer1, image_texture, NULL, &textureDestination);

		SDL_RenderPresent(renderer1);

	}
	// (5) Clear and quit 
	SDL_DestroyTexture(image_texture);
	IMG_Quit();

	SDL_DestroyRenderer(renderer1);
	SDL_DestroyWindow(window1);
	SDL_Quit();
	return 0;
}


SDL_Texture* imageTextureFromPath(SDL_Renderer* renderer,const char* path) {
	SDL_Surface* image = IMG_Load(path);
	SDL_Texture* image_texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	return image_texture;
}