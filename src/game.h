#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);

  // Game Loop
  void Run(Key::Controller const &controller, SDL::Renderer &renderer,
           std::size_t target_frame_duration);

  // Getters
  int GetScoreL() const;
  int GetSizeL() const;
  bool GetPoisonedL() const;

  int GetScoreR() const;
  int GetSizeR() const;
  bool GetPoisonedR() const;

 private:
  // Snake snake;
  // SDL_Point food;
  std::vector<std::shared_ptr<Final::Snake>> snakes_;
  std::vector<SDL_Point> foods;
  const int food_size = 4;
  std::vector<SDL_Point> poisons;
  const int poison_size = 4;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int scoreL{0};
  int scoreR{0};

  bool aliveL = true;
  bool aliveR = true;

  void PlaceFood(SDL_Point &food);
  void PlacePoison(SDL_Point &poison);
  void Update();
};

#endif