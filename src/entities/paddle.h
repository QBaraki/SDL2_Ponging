#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>

#include "geometry/vec2d.h"

class Paddle {
  struct Key {
    uint32_t binding = 0x0;
    bool IsDown = false;
  };

  SDL_Rect rect;
  Key key[3]; // [0] = up, [1] = dowm, [2] = slow.
  float velocity;

 public:
  int width, height;
  Vec2d position;

  Paddle(int width_, int height_, Vec2d position_, uint32_t up_bind_, uint32_t down_bind_, uint32_t slow_bind_);
  void Draw(SDL_Renderer* renderer);
  void Update(float delta_time);
  void HandlingKeyDown(SDL_Event* event);
  void HandlingKeyUp(SDL_Event* event);
  void InputHandler(SDL_Event* event);
  void MoveToCenter();
};

#endif  // !PADDLE_H