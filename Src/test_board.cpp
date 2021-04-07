#include "board.hpp"
#include "graphe.hpp"
#include "card.hpp"
#include <iostream>
using namespace RR;

int main() {
  Board b("board.txt");
  b.save("/tmp/cpy.txt");
  Robot rbt;
  Graphe g(rbt, b);
  g.pluscourtChemin(rbt);
  std::cout<<std::endl;
  card c;
  c.playcard();

  return 0;
}
