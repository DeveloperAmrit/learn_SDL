#include <SDL.h>

const int TILE_SIZE = 20;
const int WIDTH = 19;  // Number of columns in the maze
const int HEIGHT = 16; // Number of rows in the maze

// The 2D maze array
int maze[HEIGHT][WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// Function to render the maze
void renderMaze(SDL_Renderer* renderer) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            SDL_Rect tile;
            tile.x = col * TILE_SIZE;
            tile.y = row * TILE_SIZE;
            tile.w = TILE_SIZE;
            tile.h = TILE_SIZE;
            
            if (maze[row][col] == 1) {
                // Wall tile (blue)
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue
                SDL_RenderFillRect(renderer, &tile);
            } else if (maze[row][col] == 0) {
                // Path tile (black or background)
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black
                SDL_RenderFillRect(renderer, &tile);
            } else if (maze[row][col] == 2) {
                // Pacman (yellow circle) at position P
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Yellow
                // Drawing a simple filled rectangle as a placeholder for Pacman
                SDL_RenderFillRect(renderer, &tile);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("Pacman Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);
    
    // Render the maze
    renderMaze(renderer);
    
    SDL_RenderPresent(renderer);
    
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
