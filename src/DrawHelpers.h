#pragma once




Vector2Int MousePosToCanvasPos(Vector2Int mousePos) {
    Vector2Int canvasPos{};
    canvasPos.x = mousePos.x * CANVAS_WIDTH / SCREEN_WIDTH;
    canvasPos.y = mousePos.y * CANVAS_HEIGHT / SCREEN_HEIGHT;
    return canvasPos;
}

void DrawRect(std::vector<SDL_Color>* pixels, int x, int y, int w, int h, SDL_Color color) {
    for (int j = y; j < y + h; j++) {
        for (int i = x; i < x + w; i++) {
            // Skip if out of bounds
            if (i < 0 || i >= CANVAS_WIDTH || j < 0 || j >= CANVAS_HEIGHT) continue;
            (*pixels)[j * CANVAS_WIDTH + i] = color;
        }
    }
}
