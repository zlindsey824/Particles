#include <iostream>
#include "snow.h"

#define SPEED 1

Snow::Snow(){
  x = rand() % WIDTH;
  y = rand() % HEIGHT;
  z = rand() % 10;

  speed = (z / 3) + SPEED;
  size = z / 4;
}

void Snow::updatePosition(){
  if (y < (0-size)){
		y = HEIGHT;
		x = rand() % WIDTH;
	}
	else{
    y -= speed;
    x += rand() % ( (size < 1 ? 1 : size) * 2 + 1) - (size < 1 ? 1 : size);
  }
}

