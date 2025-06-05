#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "World.h"
#include "Grass.h"
#include "Sheep.h"
#include "Milkweed.h"
#include "Wolf.h"
#include "Toadstool.h"
#include "SdlRenderer.h"
#include <iostream>

void populateWorld(World& world) {
    world.addOrganism(new Grass(Position(2, 2)));
    world.addOrganism(new Grass(Position(17, 2)));

    world.addOrganism(new Milkweed(Position(5, 15)));
    world.addOrganism(new Milkweed(Position(15, 15)));

    world.addOrganism(new Toadstool(Position(10, 10)));

    world.addOrganism(new Sheep(Position(4, 5)));
    world.addOrganism(new Sheep(Position(10, 4)));
    world.addOrganism(new Sheep(Position(6, 16)));

    world.addOrganism(new Wolf(Position(16, 4)));
    world.addOrganism(new Wolf(Position(18, 18)));
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    const int tileSize = 20;
    World world(30, 30);
    populateWorld(world);

    SDL_Window* window = SDL_CreateWindow("Symulacja Swiata", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SdlRenderer sdlRenderer(renderer, tileSize);

    bool running = true;
    Uint32 lastUpdate = SDL_GetTicks();

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;
                if (sdlRenderer.isRestartButtonClicked(x, y)) {
                    world = World(30, 30);
                    populateWorld(world);
                }
            }
        }

        Uint32 now = SDL_GetTicks();
        if (now - lastUpdate > 500) {
            world.makeTurn();
            lastUpdate = now;
        }

        sdlRenderer.render(world);
        sdlRenderer.renderTurnText(world.getTurn());
        sdlRenderer.renderRestartButton();
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
