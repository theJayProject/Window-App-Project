#include <iostream>
#include "SDL.h"

int main(int args, char *argu[]){
    //Initialize
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    //Error Saver
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }
    if (!window){
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    if (!window_surface){
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }
    SDL_UpdateWindowSurface(window);
    //Personalize
 //   SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
 //   SDL_RenderClear(renderer);
 //   SDL_RenderPresent(renderer);
    //INPUT IMAGE
    SDL_Surface* image = SDL_LoadBMP("KFP.bmp");

    if (!image)
    {
        std::cout << "Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }


    //Prevents window from closing on its own
    bool keep_window_open = true;
    while (keep_window_open)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            }
            SDL_BlitSurface(image, NULL, window_surface, NULL);
            SDL_UpdateWindowSurface(window);
        }
        //INPUT IMAGE
    }

	return 0;
}