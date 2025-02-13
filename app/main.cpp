#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

int main(int argc, char* argv[]) {
  Game game;
  try {
    game.InitGameLoop();
  } catch (std::runtime_error err) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "An error occurred", err.what(), NULL);
  }
  return 0;
}