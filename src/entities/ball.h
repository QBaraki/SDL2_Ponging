#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

#include "paddle.h"
#include "geometry/vec2d.h"

class Ball {
  SDL_Rect rect;

 public:
  Vec2d position;
  Vec2d velocity;
  int size;

  Ball(Vec2d position_, int size_);
  void Draw(SDL_Renderer* renderer);
  void Update(float delta_time);
  int GetCollideState(Paddle& left_player, Paddle& right_player);
  void ChangeDirection(Paddle& paddle, float speed);
  void Reset();
};

#endif  // !BALL_H