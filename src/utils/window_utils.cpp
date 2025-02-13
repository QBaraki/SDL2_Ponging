#include "window_utils.h"
#include "../common.h"

void WindowUtils::Center(SDL_Window* window) {
  SDL_DisplayMode DM;

  SDL_GetCurrentDisplayMode(0, &DM);
  SDL_SetWindowPosition(window, (DM.w - WINDOW_WIDTH) / 2, (DM.h - WINDOW_HEIGHT) / 2);
}