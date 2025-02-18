#include "renderer_utils.h"

void RendererUtils::DrawNet(SDL_Renderer* renderer, int window_width, int window_height) {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  int current = 0;
  for (int y = 0; y < window_height; y++) {
    if (current < 10) {
      SDL_RenderDrawPoint(renderer, window_width / 2, y);
    }
    if (current == 15) {
      current = 0;
    } else {
      current++;
    }
  }
}