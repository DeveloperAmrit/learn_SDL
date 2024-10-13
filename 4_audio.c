#include <SDL.h>
#include <SDL_mixer.h>
#include <stdbool.h>

const int width = 500;
const int height = 400;


int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

	SDL_Window* window1 = SDL_CreateWindow("Home page", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// (1) initialize mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// (2) Allocate channel to play sound effects simultaneously
	Mix_AllocateChannels(16);

	// (3) Load audio files
	Mix_Music* backgroundSound = Mix_LoadMUS("C:/Users/Hp/Music/ic_sem1_project/pacman_music.mp3");
	Mix_Chunk* jumpEffect = Mix_LoadWAV("C:/Users/Hp/Music/bfxr/Jump.wav");
	Mix_Chunk* laserEffect = Mix_LoadWAV("C:/Users/Hp/Music/bfxr/Laser_Shoot.wav");

	// (4) Good place to start is before main loop
	Mix_PlayMusic(backgroundSound,-1);      // -1 for infinite, 0 for one

	bool running = true;
	SDL_Event event;
	while (running)
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				
				// press space for jumpEffect
				if (event.key.keysym.sym == SDLK_SPACE) {
					Mix_PlayChannel(-1, jumpEffect, 0);
				}
				// press f for laserEffect
				else if (event.key.keysym.sym == SDLK_f) {
					Mix_PlayChannel(-1, laserEffect, 0);
				}
			}
		}

		SDL_RenderClear(renderer1);
		

		SDL_RenderPresent(renderer1);
	}

	SDL_DestroyRenderer(renderer1);
	SDL_DestroyWindow(window1);
	Mix_FreeMusic(backgroundSound);
	Mix_FreeChunk(jumpEffect);
	Mix_FreeChunk(laserEffect);
	Mix_CloseAudio();
	SDL_Quit();
}