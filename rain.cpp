#include <iostream>
#include "rain.h"

#define SPEED 5

Rain::Rain(){
	x = rand() % 500;
	y = rand() % 500;
	z = rand() % 20 + 1; 
	
	speed = z + SPEED;
	size = (z / 3) + 1;
}

void Rain::updatePosition(){
	if (y < (0-size)){
		y = 499;
		x = rand() % 500;
	}
	else 
		y -= speed;
}
