#ifndef RAIN_H
#define RAIN_H

class Rain{
public:
	Rain();
	void updatePosition();
	
	int getX(){ return x ;}
	int getY(){ return y ;}
	int getZ(){ return z ;}
	int getSize(){ return size; }
	
private:
	int x;
	int y;
	int z;
	int speed;
	int size;
};

#endif
