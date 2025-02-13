#include "renderer_utils.h"

void RendererUtils::DrawNet(SDL_Renderer* renderer, int window_width, int window_height) {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  int cur = 0;

  for (int y = 0; y < window_height; y++) {
    if (cur < 10) {
      SDL_RenderDrawPoint(renderer, window_width / 2, y);
    }

    if (cur == 15) {
      cur = 0;
    }
    else {
      cur++;
    }
  }
}