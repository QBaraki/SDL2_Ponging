#ifndef MATCH_H
#define MATCH_H

#include <SDL2/SDL.h>

#include <vector>

#include "game/player.h"

class Match {
  SDL_Renderer* renderer;
  std::vector<Player*> players;

 public:
  Match(SDL_Renderer* renderer_);
  ~Match();
  void Draw();
  void Update(float delta_time);
  void InputHandler(SDL_Event* event);
  void Reset();
};

#endif  // !MATCH_H