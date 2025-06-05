#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "World.h"

class SdlRenderer {
public:
    SdlRenderer(SDL_Renderer* renderer, int tileSize);
    void render(const World& world);
    void renderTurnText(int turn);
    void renderRestartButton();
    bool isRestartButtonClicked(int mouseX, int mouseY) const;
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    int tileSize;
    SDL_Rect restartButton;

    SDL_Color getColorForCode(const std::string& code) const;
    void drawText(const std::string& text, int x, int y, SDL_Color color);
};
