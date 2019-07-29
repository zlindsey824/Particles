#include "controller.h"

Controller::Controller(int num, char type):
	numOfParticles(num)
{
	if (type == 'r')
		particles = new Rain[numOfParticles];
}

Controller::~Controller(){
	delete[] particles;
}

Particle* Controller::returnParticle(int index){
	return &particles[index];
}
