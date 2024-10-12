#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>          
#include <stdlib.h>
#include "2.h"

const height = 500;
const width = 500;

void drawRandomPoints(int nmr_points, bool randomizeColor, SDL_Renderer* renderer) {
	for (int i = 0;i < nmr_points;i++) {
		if (randomizeColor) {
			SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
		}
		SDL_RenderDrawPoint(renderer, random(0, width), random(0, height));
	}
}

void drawRandomLines(int nmr_lines, bool randomizeColor, SDL_Renderer* renderer) {
	for (int i = 0;i < nmr_lines;i++) {
		if (randomizeColor) {
			SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
		}
		SDL_RenderDrawLine(renderer, random(0, width), random(0, height), random(0, width), random(0, height));
	}
}

void drawRectangle(int top_left_x, int top_left_y,int width, int height,int r,int g,int b, int a,bool fill, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_Rect rect = { top_left_x,top_left_y,width,height };  // why not * here, because no function on RHS returning a pointer
	(fill)? SDL_RenderFillRect(renderer, &rect) : SDL_RenderDrawRect(renderer, &rect);
}

void drawBorderedRectangle(int top_left_x, int top_left_y, int width, int height, int r, int g, int b, int a, int br, int bg,int bb, int ba, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, br, bg, bb, ba);
	SDL_Rect rect1 = { top_left_x,top_left_y,width,height };
	SDL_RenderDrawRect(renderer, &rect1);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_Rect rect2 = { top_left_x + 1,top_left_y + 1,width - 2,height - 2 };
	SDL_RenderFillRect(renderer, &rect2);
}

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window1 = SDL_CreateWindow("MyApp", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	// window1 is a pointer to the structure SDL_Window
	// SDL_Create... functions return a pointer to the objects on LHS i.e SDL_Window

	bool running = true;
	SDL_Event event1;
	while (running){
		while (SDL_PollEvent(&event1)) {
			if (event1.type == SDL_QUIT) {
				running = false;
			}
		}
		// set background otherwise SDL_SetRenderColor will change bg instead of color of points
		SDL_SetRenderDrawColor(renderer1, 0, 0, 0, 255);

		// clear any junk
		SDL_RenderClear(renderer1);

		// now do your drawing
		//drawRandomPoints(10, true, renderer1);

		//drawRandomLines(10, true, renderer1);

		drawRectangle(10, 10, 50, 50,255,255,0,255,false, renderer1);

		drawBorderedRectangle(50, 50, 80, 30, 0, 0, 255, 255, 255, 255, 255, 255, renderer1);

		SDL_RenderPresent(renderer1);

	}

	SDL_DestroyRenderer(renderer1);
	SDL_DestroyWindow(window1);

	SDL_Quit();

	return 0;


}