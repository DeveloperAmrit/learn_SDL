#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>            // lets us use boolean variables.
#include <stdlib.h>

const int width = 400;
const int height = 400;

int main(int argc, char** argv) {                  // compulsory parameters
	// (1) Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	/*
	SDL_Init(parameters of type of windows)
	Can take multiple types seperated by | enabling all metioned features involved
	* SDL_INIT_AUDIO : Initializes the audio subsystem, allowing you to handle audio playback and recording.
	* SDL_INIT_JOYSTICK: Initializes joystick support, enabling you to work with game controllers and other joystick devices.
	* SDL_INIT_GAMECONTROLLER: Initializes the game controller subsystem, providing support for gamepad-like devices with better input handling.
	* SDL_INIT_EVENTS: Initializes the event subsystem, which is necessary for handling various input events (keyboard, mouse, etc.). (automatically initiated)
	* SDL_INIT_TIMER: Initializes the timer subsystem, which is useful for creating timers and handling time-related functions.
	* SDL_INIT_HAPTIC: Initializes haptic (force feedback) support for game controllers, allowing you to create vibrating effects.
	* SDL_INIT_NOPARACHUTE : Disables automatic error handling called parachute mechanism. (not reccomended)

	*/

	// (2) creating a window
	SDL_Window* window1 = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	/*
	SDL_CreateWindow(title,x-pos,y-pos,width,height,width, additional parameters)
	Useful parameters :
	* SDL_WINDOW_FULLSCREEN : to full screen the window.
	* SDL_WINDOW_OPENGL: To create an OpenGL context window. (gives additional OpenGL API tools)
	* SDL_WINDOW_SHOW : To create a window that is visible immediately after creation. (default)
	* SDL_WINDOW_HIDDEN : To create a window that is not visible after creation. (use SDL_ShowWindow() function to show it)
	* SDL_WINDOW_BORDERLESS : To create a window without any border.
	* SDL_WINDOW_RESIZABLE : To create a resizable window.
	*/

	// (3) creating renderer
	SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	/*
	SDL_CreateRenderer(windowname, z-index, additonal parameters)
	Each window has its own renderer, use multiple renderers for multiple windows
	If used the same renederer the previous window is destroyed and new window is shown.
	Useful parameters :
	* SDL_RENDERER_PRESENTVSYNC : Synchronizes the rendering with vertical display refresh rate (Vsync).
								  Prevent screen tearing. Smooth ouput at cost of potntial input lag.
	* SDL_RENDERER_TARGETTEXTURE : Offscreen rendering for later use.
	* SDL_RENDERER_SOFTWARE: This flag creates a software renderer.
							 It is useful if you want to ensure compatibility across systems but may be slower than hardware-accelerated rendering.
	* SDL_RENDERER_ACCELERATED : Hardware-accelerated renderer, which uses the GPU to improve performance.
	*/

	// (4) the game loop
	bool running = true;
	SDL_Event event1;
	while (running)
	{
		// (4) User exit
		while (SDL_PollEvent(&event1))
		{
			if (event1.type == SDL_QUIT) {
				running = false;
			}

		}
		// (5) The actual program

		// (i) clear the renderers
		SDL_RenderClear(renderer1);

		// (ii) draw
		SDL_SetRenderDrawColor(renderer1, 255, 0, 0, 255);

		// (iii) show that was drawn
		SDL_RenderPresent(renderer1);
	}


	// destroying any renederer or window  // permanent destruction no show again
	// use SDL_ShowWindow() and SDL_HideWindow() for temprorary hiding

	SDL_DestroyRenderer(renderer1);
	SDL_DestroyWindow(window1);

	// release resources
	SDL_Quit();

	return 0;
}