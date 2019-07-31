#ifndef FIRE_H
#define FIRE_H

#include "particle.h"

class Fire: public Particle{
  public:
    Fire();
    void updatePosition();
};

#endif
