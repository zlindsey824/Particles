#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "particle.h"
#include "rain.h"

class Controller{
public:
	Controller(int num, char type);
	~Controller();
	Particle* returnParticle(int index);
private:
	Particle* particles;
	int numOfParticles;
};

#endif
