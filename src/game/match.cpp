#include "match.h"

#include "common.h"
#include "entities/paddle.h"
#include "utils/renderer_utils.h"

#include <iostream>

Match::Match(SDL_Renderer* renderer_) {
  renderer = renderer_;
  players = {new Player(renderer, 0), new Player(renderer, 1)};
  speed = 0.35f;
}

Match::~Match() {
  for (Player* player : players) {
    delete player;
  }
}

void Match::Draw() {
  RendererUtils::DrawNet(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
  ball.Draw(renderer);
  for (Player* player : players) {
    player->Draw();
  }
}

void Match::Update(float delta_time) {
  ball.Update(delta_time);
  for (Player* player : players) {
    player->Update(delta_time);
  }
  int collide_state = ball.GetCollideState(*players[0]->paddle, *players[1]->paddle);
  switch (collide_state) {
    case -1: {
      std::cout << "Right player won!\n";
      // SDL_Delay(5000);
      Reset();
      ball.velocity.x *= -1;
      break;
    }
    case -2: {
      std::cout << "Left player won!\n";
      // SDL_Delay(5000);
      Reset();
      ball.velocity.x *= -1;
      break;
    }
    case 1: {
      std::cout << "Collided with left player.\n";
      speed += 0.05f;
      ball.ChangeDirection(*players[0]->paddle, speed);
      break;
    }
    case 2: {
      std::cout << "Collided with right player.\n";
      speed += 0.05f;
      ball.ChangeDirection(*players[1]->paddle, speed);
      break;
    }
    default:
      break;
  }
}

void Match::InputHandler(SDL_Event* event) {
  for (Player* player : players) {
    player->InputHandler(event);
  }
}

void Match::Reset() {
  ball.Reset();
  speed = 0.35f;
  ball.velocity = Vec2d(speed, 0);
  for (Player* player : players) {
    player->Reset();
  }
}