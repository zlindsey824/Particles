#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
  public:
    virtual void updatePosition() = 0;

    int getX(){ return x; }
  	int getY(){ return y; }
  	int getZ(){ return z; }
  	int getSize(){ return size; }

  protected:
    int x;
    int y;
    int z;
    int speed;
    int size;
};
