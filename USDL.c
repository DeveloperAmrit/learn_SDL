// Not of your use
// this is the Ultimate SDL file, here you will find all derived functions to be used directly

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>          
#include <stdlib.h>

int random(int min_int, int max_int) {
	static bool initialized = false;
	if (!initialized) {
		initialized = true;
		srand(time(NULL));
	}
	return rand() % max_int + min_int;
}

int randomColor() {
	return random(0, 255);
}

void drawRandomPoints(int nmr_points, bool randomizeColor,int x,int y,int width,int height, SDL_Renderer* renderer) {
	for (int i = 0;i < nmr_points;i++) {
		if (randomizeColor) {
			SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
		}
		SDL_RenderDrawPoint(renderer, random(x, x+width), random(y, y+height));
	}
}

void drawRandomLines(int nmr_lines, bool randomizeColor,int x,int y,int width,int height, SDL_Renderer* renderer) {
	for (int i = 0;i < nmr_lines;i++) {
		if (randomizeColor) {
			SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
		}
		SDL_RenderDrawLine(renderer, random(x, x+width), random(y, y+height), random(x, x+width), random(y, y+height));
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