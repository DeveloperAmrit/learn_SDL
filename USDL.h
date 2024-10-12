// register functions defined in USDL.c

#pragma once
// USDL.h
#ifndef ONE_H
#define ONE_H

// Function declaration
int randomColor();
int random(int min_int,int max_int);
void drawRandomPoints(int nmr_points, bool randomizeColor,int width,int height, SDL_Renderer* renderer);
void drawRandomLines(int nmr_lines, bool randomizeColor,int width, int height, SDL_Renderer* renderer);
void drawRectangle(int top_left_x, int top_left_y,int width, int height,int r,int g,int b, int a,bool fill, SDL_Renderer* renderer);
void drawBorderedRectangle(int top_left_x, int top_left_y, int width, int height, int r, int g, int b, int a, int br, int bg,int bb, int ba, SDL_Renderer* renderer);


#endif
