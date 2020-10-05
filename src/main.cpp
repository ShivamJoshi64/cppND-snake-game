#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"


// Entry point
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  SDL::Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Key::Controller controller;

  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

  if (!game.GetPoisonedL() && game.GetPoisonedR()) {
    std::cout << "Left snake ate poison, Right snake wins!!!" << "\n";
    return 0;
  }
  if (game.GetPoisonedR() && !game.GetPoisonedR()) {
    std::cout << "Right snake ate poison, Left snake wins!!!" << "\n";
    return 0;
  }

  std::cout << "Game has terminated successfully!\n";

  std::cout << "Score Left: " << game.GetScoreL() << "\n";
  std::cout << "Size Left: " << game.GetSizeL() << "\n";

  std::cout << "Score Right: " << game.GetScoreL() << "\n";
  std::cout << "Size Right: " << game.GetSizeR() << "\n";

  if (game.GetScoreR() > game.GetScoreL()) {
    std::cout << "Right snake wins!!!" << "\n";
  } 
  else if (game.GetScoreR() < game.GetScoreL()) {
    std::cout << "Left snake wins!!!" << "\n";
  } 
  else {
    std::cout << "It's a Tie!" << "\n";
  }
  return 0;
}

