#include <iostream>
#include "rain.h"

#define SPEED 5

Rain::Rain(){
	x = rand() % WIDTH;
	y = rand() % HEIGHT;
	z = rand() % 20 + 1;

	speed = (z / 4) + SPEED;
	size = z / 7;
}

void Rain::updatePosition(){
	if (y < (0-size)){
		y = HEIGHT;
		x = rand() % WIDTH;
	}
	else
		y -= speed;
}
