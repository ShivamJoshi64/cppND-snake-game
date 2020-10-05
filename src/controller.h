#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

namespace Key{
class Controller {
 public:
  void HandleInput(bool &running,std::vector<std::shared_ptr<Final::Snake>> &snakes) const;

 private:
  void ChangeDirection(std::shared_ptr<Final::Snake> snake, Final::Snake::Direction input,Final::Snake::Direction opposite) const;
};
}
#endif