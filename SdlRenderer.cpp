#include "SdlRenderer.h"
#include <SDL2/SDL_ttf.h>
#include <map>
#include "World.h"

SdlRenderer::SdlRenderer(SDL_Renderer* renderer, int tileSize)
    : renderer(renderer), tileSize(tileSize) {
    TTF_Init();
    font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 20);
    restartButton = {20, 520, 120, 40};
}

SDL_Color SdlRenderer::getColorForCode(const std::string& code) const {
    if (code == "S") return {12, 111, 253, 255};
    if (code == "W") return {0, 0, 0, 255};
    if (code == "G") return {0, 255, 0, 255};
    if (code == "M") return {128, 0, 128, 255};
    if (code == "T") return {255, 0, 0, 255};
    return {192, 192, 192, 255};
}

void SdlRenderer::render(const World& world) {
    int rows = world.getWorldY();
    int cols = world.getWorldX();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            SDL_Rect rect = {x * tileSize, y * tileSize + 40, tileSize, tileSize};
            std::string code = world.getOrganismFromPosition(x, y);
            SDL_Color color = getColorForCode(code);
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void SdlRenderer::drawText(const std::string& text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dst = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void SdlRenderer::renderTurnText(int turn) {
    drawText("Tura: " + std::to_string(turn), 20, 5, {0, 0, 0, 255});
}

void SdlRenderer::renderRestartButton() {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &restartButton);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &restartButton);
    drawText("Restart", restartButton.x + 10, restartButton.y + 10, {0, 0, 0, 255});
}

bool SdlRenderer::isRestartButtonClicked(int mouseX, int mouseY) const {
    return mouseX >= restartButton.x && mouseX <= restartButton.x + restartButton.w &&
           mouseY >= restartButton.y && mouseY <= restartButton.y + restartButton.h;
}
