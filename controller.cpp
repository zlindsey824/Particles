#include "controller.h"

Controller::Controller(int num, char type):
	numOfParticles(num)
{
	switch (type){
		case 'r':
			particles = new Rain[numOfParticles];
			break;
		case 's':
			particles = new Snow[numOfParticles];
			break;
		case 'f':
			break;
		default:
			break;
	}

}

Controller::~Controller(){
	delete[] particles;
}

Particle* Controller::returnParticle(int index){
	return &particles[index];
}
