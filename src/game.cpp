#include "game.h"

#include "common.h"
#include "utils/window_utils.h"

#include <stdexcept>

Game::Game() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    throw std::runtime_error("Failed to initialize SDL. SDL error: " + std::string(SDL_GetError()));
  }
  window = SDL_CreateWindow("Ponging", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    throw std::runtime_error("Failed to create SDL window. SDL error: " + std::string(SDL_GetError()));
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == nullptr) {
    throw std::runtime_error("Failed to create SDL renderer window. SDL error: " + std::string(SDL_GetError()));
  }
  WindowUtils::Center(window);
}

Game::~Game() {
  SDL_DestroyWindow(window);
  window = nullptr;
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
  TTF_CloseFont(font);
  font = nullptr;
  TTF_Quit();
  SDL_Quit();
}

void Game::InitGameLoop() {
  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
}