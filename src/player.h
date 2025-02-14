#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "entities/paddle.h"

class Player {
  SDL_Renderer* renderer;

 public:
  Paddle* paddle;

  Player(SDL_Renderer* renderer_, bool which_player);
  ~Player();
  void Draw();
  void Update(float delta_time);
  void InputHandler(SDL_Event* event);
  void Reset();
};

#endif  // PLAYER_H