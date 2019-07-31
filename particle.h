#ifndef PARTICLE_H
#define PARTICLE_H

#define WIDTH 500
#define HEIGHT 500

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
#endif
