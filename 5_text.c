#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>

const int WindowWidth = 400;
const int WindowHeight = 300;

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Window* window = SDL_CreateWindow("TextInSDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// load font
	TTF_Font* font1 = TTF_OpenFont("C:/SDL2_libraries_/fontsttf/Pixelify_Sans/PixelifySans-VariableFont_wght.ttf", 24);
	SDL_Color textColor = { 255,255,255,255 };

	// load font on surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font1, "PACMAN", textColor);

	// create texture 
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	// create rectangle to place texture
	int width = 300;
	int height = 200;
	SDL_Rect textRect = { (WindowWidth -width)/2, (WindowHeight -height)/2, width,height };

	// clear renderer
	SDL_RenderClear(renderer);

	// copy into renderer
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

	SDL_Event event;
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
		// present
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(textTexture);
	TTF_CloseFont(font1);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	return 0;
}