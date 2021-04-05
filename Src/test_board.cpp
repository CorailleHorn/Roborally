#include "board.hpp"
#include "graphe.hpp"
#include <iostream>
using namespace RR;

int main() {
  Board b("board.txt");
  b.save("/tmp/cpy.txt");
  Robot rbt;
  Graphe g(rbt, b);


  return 0;
}
