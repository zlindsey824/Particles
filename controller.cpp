#include "controller.h"

Controller::Controller(int num):
	numOfParticles(num)
{
	particles = new Rain[numOfParticles];
}

Controller::~Controller(){
	delete[] particles;
}

Rain* Controller::returnParticle(int index){
	return &particles[index];
}
