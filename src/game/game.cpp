#include "game.h"

#include "common.h"
#include "utils/window_utils.h"
#include "utils/renderer_utils.h"
#include "match.h"

#include <stdexcept>
#include <chrono>

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
  font = nullptr;
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
  Match match(renderer);
  match.Reset();
  while (running) {
    SDL_Event event;
    auto frame_start_time = std::chrono::high_resolution_clock::now();
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
      match.InputHandler(&event);
    }
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 255);
    SDL_RenderClear(renderer);
    match.Update(status.delta_time);
    match.Draw();
    SDL_RenderPresent(renderer);
    auto frame_stop_time = std::chrono::high_resolution_clock::now();
    status.delta_time = std::chrono::duration<float, std::chrono::milliseconds::period>(frame_stop_time - frame_start_time).count();
  }
}