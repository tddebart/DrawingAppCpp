#define CANVAS_WIDTH 800
#define CANVAS_HEIGHT 600

#include <iostream>
#include "SDL/SetupSDL.h"
#include "SDL/Input.h"
#include "ScreenInfo.h"
#include "Vector2.h"
#include "DrawHelpers.h"

// Pixels
std::vector<SDL_Color> pixels = std::vector<SDL_Color>(CANVAS_WIDTH * CANVAS_HEIGHT, {255, 255, 255, 255});
SDL_Texture* canvasTexture = nullptr;

void mousePosToCanvasPos(int& x, int& y) {
    x = x * CANVAS_WIDTH / SCREEN_WIDTH;
    y = y * CANVAS_HEIGHT / SCREEN_HEIGHT;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    InitSDL();
    
    canvasTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, CANVAS_WIDTH, CANVAS_HEIGHT);

    while (!done) {
        handleInput();
        
        SDL_RenderClear(renderer);
        
        if (isMouseDown(1)) {
            auto mousePos = (Vector2Int)getMousePosition();
//            mousePos = MousePosToCanvasPos(mousePos);
            // Draw a rectangle in the canvas
            DrawRect(&pixels, mousePos.x-5, mousePos.y-5, 10, 10, {255, 0, 0, 255});
        }
        
        SDL_UpdateTexture(canvasTexture, nullptr, pixels.data(), CANVAS_WIDTH * sizeof(SDL_Color));
        // Don't stretch the texture
        SDL_Rect canvasRect{0, 0, CANVAS_WIDTH, CANVAS_HEIGHT};
        SDL_RenderCopy(renderer, canvasTexture, nullptr, &canvasRect);

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
