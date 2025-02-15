#include "player.h"

#include "common.h"

Player::Player(SDL_Renderer* renderer_, bool which_player) {
  renderer = renderer_;
  if (!which_player) {  // Left player.
    paddle = new Paddle(10, 100, Vec2d(10, 0), SDLK_w, SDLK_s, SDLK_LSHIFT);
  } else {              // Right player.
    paddle = new Paddle(10, 100, Vec2d(WINDOW_WIDTH - 20, 0), SDLK_UP, SDLK_DOWN, SDLK_RSHIFT);
  }
}

Player::~Player() {
  delete paddle;
}

void Player::Draw() {
  paddle->Draw(renderer);
}

void Player::Update(float delta_time) {
  paddle->Update(delta_time);
}

void Player::InputHandler(SDL_Event* event) {
  paddle->InputHandler(event);
}

void Player::Reset() {
  paddle->MoveToCenter();
}