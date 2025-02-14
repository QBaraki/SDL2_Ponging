#ifndef GAME_H
#define GAME_H

#include <SDL_ttf.h>
#include <SDL2/SDL.h>

class Game {
  SDL_Window* window;
  SDL_Renderer* renderer;
  TTF_Font* font;

 public:
  Game();
  ~Game();
  void InitGameLoop();
};

#endif  // GAME_H