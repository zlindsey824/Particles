#ifndef RAIN_H
#define RAIN_H

#include "particle.h"

class Rain: public Particle{
	public:
		Rain();
		void updatePosition();
};

#endif
