#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "rain.h"

class Controller{
public:
	Controller(int num);
	~Controller();
	Rain* returnParticle(int index);
private:
	Rain* particles;
	int numOfParticles;
};

#endif
