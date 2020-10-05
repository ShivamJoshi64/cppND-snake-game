#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Key::Controller::ChangeDirection(std::shared_ptr<Final::Snake> snake,
                                      Final::Snake::Direction input,
                                      Final::Snake::Direction opposite) const {
  if (snake->direction != opposite || snake->size == 1)
    snake->direction = input;
}

void Key::Controller::HandleInput(bool &running, std::vector<std::shared_ptr<Final::Snake>> &snakes) const {
  SDL_Event e;
  auto snakeL = snakes[0];
  auto snakeR = snakes[1];
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        using namespace Final;
        case SDLK_w:
          ChangeDirection(snakeL, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_s:
          ChangeDirection(snakeL, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_a:
          ChangeDirection(snakeL, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_d:
          ChangeDirection(snakeL, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        case SDLK_UP:
          ChangeDirection(snakeR, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snakeR, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snakeR, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snakeR, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}