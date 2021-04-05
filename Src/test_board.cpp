#include "board.hpp"
#include "graphe.hpp"
#include <iostream>
using namespace RR;

int main() {
  Board b("board.txt");
  b.save("/tmp/cpy.txt");
  Robot rbt;
  rbt.location = Location(0,1);
  rbt.status = Robot::Status::EAST;
  Graphe g(rbt, b);

  return 0;
}
