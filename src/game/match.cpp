#include "match.h"

#include "common.h"
#include "entities/paddle.h"
#include "utils/renderer_utils.h"

#include <iostream>

Match::Match(SDL_Renderer* renderer_) {
  renderer = renderer_;
  players = {new Player(renderer, 0), new Player(renderer, 1)};
}

Match::~Match() {
  for (Player* player : players) {
    delete player;
  }
}

void Match::Draw() {
  RendererUtils::DrawNet(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
  for (Player* player : players) {
    player->Draw();
  }
}

void Match::Update(float delta_time) {
  for (Player* player : players) {
    player->Update(delta_time);
  }
}

void Match::InputHandler(SDL_Event* event) {
  for (Player* player : players) {
    player->InputHandler(event);
  }
}

void Match::Reset() {
  for (Player* player : players) {
    player->Reset();
  }
}