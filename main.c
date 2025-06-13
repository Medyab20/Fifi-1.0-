#include <SDL2/SDL.h>
#include <stdio.h>

void launch_calculator();
void launch_notes();
void launch_finder();
void launch_settings();
void launch_timer();

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Fifi OS",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    int running = 1;
    SDL_Event event;

    while (running) {
        SDL_SetRenderDrawColor(renderer, 200, 200, 255, 255);
        SDL_RenderClear(renderer);

        // Hier zou je knoppen tekenen

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_1) launch_calculator();
                if (event.key.keysym.sym == SDLK_2) launch_notes();
                if (event.key.keysym.sym == SDLK_3) launch_finder();
                if (event.key.keysym.sym == SDLK_4) launch_settings();
                if (event.key.keysym.sym == SDLK_5) launch_timer();
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

