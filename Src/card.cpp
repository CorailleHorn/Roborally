#include "cards.hpp"

Cards::Cards() {
}

int Cards::getcard(){
  return rand()% 6 + 0;
}

void Cards::drawcard(){
  int carte;
  for(int i=0;i<9;i++)
  {
    carte=getcard();
    draw.push_back(moves[carte]);
  }
}

std::vector<RR::Robot::move)> Cards::get9cards(){
  for(int i=0;i<9;i++)
  {
    return draw[i];
  }
}
