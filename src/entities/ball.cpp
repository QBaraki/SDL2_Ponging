#include "ball.h"

#include "common.h"

#include <utility>
#include <stdexcept>
#include <cmath>

Ball::Ball(Vec2d position_, int size_) {
  position = position_;
  size = size_;
  velocity = Vec2d();
  rect.x = static_cast<int>(position.x);
  rect.y = static_cast<int>(position.y);
  rect.w = rect.h = size;
}

void Ball::Draw(SDL_Renderer* renderer) {
  rect.x = static_cast<int>(position.x);
  rect.y = static_cast<int>(position.y);
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &rect);
}

void Ball::Update(float delta_time) {
  position += velocity * delta_time;
  if (position.y < 0) {
    velocity.y = std::fabs(velocity.y);
  } else if (position.y > WINDOW_HEIGHT) {
    velocity.y = -std::fabs(velocity.y);
  }
}

int Ball::GetCollideState(Paddle& left_player, Paddle& right_player) {
  if (position.x < WINDOW_WIDTH / 2.0f) {
    if (position.x < 0) {
      return -1;
    }
    if (position.x > left_player.position.x + left_player.width || position.x < left_player.position.x) {
      return 0;
    }
    if (left_player.position.y <= position.y + size && position.y <= left_player.position.y + left_player.height) {
      return 1;
    }
  } else {
    if (position.x + size > WINDOW_WIDTH) {
      return -2;
    }
    if (position.x + size < right_player.position.x || position.x + size > right_player.position.x + right_player.width) {
      return 0;
    }
    if (right_player.position.y <= position.y + size && position.y <= right_player.position.y + right_player.height) {
      return 2;
    }
  }
  return 0;
}

void Ball::ChangeDirection(Paddle& paddle, float speed) {
  float angle = (position.y + size / 2.0f) - (paddle.position.y + paddle.height / 2.0f);
  angle *= 1.2;
  angle = std::min(angle, 50.0f);
  angle = std::max(angle, -50.0f);
  velocity.x = speed * (velocity.x < 0 ? 1 : -1);
  velocity.y = std::tan(angle * 3.14159f / 180.0f) * std::fabs(velocity.x);
}

void Ball::Reset() {
  position.x = (WINDOW_WIDTH - size) / 2.0f;
  position.y = (WINDOW_HEIGHT - size) / 2.0f;
}