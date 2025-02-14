#include "paddle.h"

#include "common.h"

const float kSpeed = 0.75f;

Paddle::Paddle(int width_, int height_, Vec2d position_, uint32_t up_bind_, uint32_t down_bind_, uint32_t slow_bind_) {
  width = width_;
  height = height_;
  position = position_;
  key[0].binding = up_bind_;
  key[1].binding = down_bind_;
  key[2].binding = slow_bind_;
  rect.x = static_cast<int>(position_.x);
  rect.y = static_cast<int>(position_.y);
  rect.w = width;
  rect.h = height;
  velocity = 0.0f;
}

void Paddle::Draw(SDL_Renderer* renderer) {
  rect.x = static_cast<int>(position.x);
  rect.y = static_cast<int>(position.y);
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &rect);
}

void Paddle::Update(float delta_time) {
  position.x += velocity * delta_time;
  if (position.x < 0) {
    position.x = 0;
  } else if (position.y > WINDOW_HEIGHT - height) {
    position.x = WINDOW_HEIGHT - height;
  }
}

void Paddle::HandlingKeyDown(SDL_Event* event) {
  if (event->key.keysym.sym == key[0].binding) {          // Go up.
    velocity = -kSpeed / (key[2].IsDown ? 2.5f : 1.0f);
    key[0].IsDown = true;
  } else if (event->key.keysym.sym == key[1].binding) {   // Go down.
    velocity = kSpeed / (key[2].IsDown ? 2.5f : 1.0f);
    key[1].IsDown = true;
  } else if (event->key.keysym.sym == key[2].binding) {   // Slow.
    key[2].IsDown = true;
  }
}

void Paddle::HandlingKeyUp(SDL_Event* event) {
  if (event->key.keysym.sym == key[0].binding) {
    key[0].IsDown = false;
  } else if (event->key.keysym.sym == key[1].binding) {
    key[1].IsDown = false;
  } else if (event->key.keysym.sym == key[2].binding) {
    key[2].IsDown = false;
  }
  if (!key[0].IsDown && !key[1].IsDown) {
    velocity = 0.0f;
  } else if (key[0].IsDown && !key[1].IsDown) {
    velocity = -kSpeed / (key[2].IsDown ? 2.5f : 1.0f);
  } else if (!key[0].IsDown && key[1].IsDown) {
    velocity = kSpeed / (key[2].IsDown ? 2.5f : 1.0f);
  }
 }

void Paddle::InputHandler(SDL_Event* event) {
  if (event->type == SDL_KEYDOWN) {
    HandlingKeyDown(event);
  } else if (event->type == SDL_KEYUP) {
    HandlingKeyUp(event);
  }
}

void Paddle::MoveToCenter() {
  position.y = (WINDOW_HEIGHT - height) / 2.0;
}