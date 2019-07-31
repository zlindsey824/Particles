#include "fire.h"

#define SPEED 5

Fire::Fire(int x, int y):x(x), y(y){
	z = rand() % 20 + 1;

	speed = (z / 4) + SPEED;
	size = z / 7;
}

void Fire::updatePosition(){
	if (y < (0-size)){
		y = HEIGHT;
		x = rand() % WIDTH;
	}
	else
		y -= speed;
}
