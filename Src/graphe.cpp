#include "graphe.hpp"
#include <vector>
#include "board.hpp"

graphe::initGraphe(RR::Robot init, RR::Board* board) {
  Noeud n0;
  n0.rbt.location = init.location;
  n0.rbt.satus = init.status;
}
