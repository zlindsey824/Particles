#ifndef SNOW_H
#define SNOW_H

#include "particle.h"

class Snow: public Particle{
	public:
		Snow();
		void updatePosition();
};

#endif
