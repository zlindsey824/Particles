//
//
//							This file provided by Victor Zordan in Computer Graphics class
//
//
//
/***************************************************************************/

                                                   /* Include needed files */
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "controller.h"

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header

#define WIDTH 500
#define HEIGHT 500

#define COUNT 50

int x_last,y_last;
bool paused = false;
Controller particles(COUNT,'s');
const GLfloat rainColor[4] = {0.30, 0.74, 0.76, 1.0};

/***************************************************************************/

void init_window()
                 /* Clear the image area, and set up the coordinate system */
{

        					       /* Clear the window */
        glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
        glOrtho(0,WIDTH,0,HEIGHT,-1.0,1.0);
}

/***************************************************************************/

void write_pixel(int x, int y, double intensity, int size)
                                         /* Turn on the pixel found at x,y */
{

        glColor4fv (rainColor);
        glBegin(GL_POINTS);
        if (size >= 0)
           glVertex3i( x, y, 0);
         if (size >= 1)
         	 glVertex3i( x, y+1, 0);
       	 if (size >= 2) {
       	 	 glVertex3i( x, y+2, 0);
           glVertex3i( x+1, y, 0);
           glVertex3i( x+1, y+1, 0);
           glVertex3i( x+1, y+2, 0);
         }
        glEnd();
}

//***************************************************************************/

void display ( void )   // Create The Display Function
{
	int x,y,z,size;
	if (!paused){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen

		for (int i = 0; i < COUNT; i++){
			x = particles.returnParticle(i)->getX();
			y = particles.returnParticle(i)->getY();
			z = particles.returnParticle(i)->getZ();
			size = particles.returnParticle(i)->getSize();
			write_pixel(x, y, z, size);
			particles.returnParticle(i)->updatePosition();
		}
	}

  glutSwapBuffers();                                      // Draw Frame Buffer
}

/***************************************************************************/
void mouse(int button, int state, int x, int y)
{
/* This function I finessed a bit, the value of the printed x,y should
   match the screen, also it remembers where the old value was to avoid multiple
   readings from the same mouse click.  This can cause problems when trying to
   start a line or curve where the last one ended */
        static int oldx = 0;
        static int oldy = 0;
	int mag;

	y *= -1;  //align y with mouse
	y += 500; //ignore
	mag = (oldx - x)*(oldx - x) + (oldy - y)*(oldy - y);
	if (mag > 20) {
		printf(" x,y is (%d,%d)\n", x,y);
	}
	oldx = x;
	oldy = y;
	x_last = x;
	y_last = y;
}

/***************************************************************************/
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27:              // When Escape Is Pressed...
			exit ( 0 );   // Exit The Program
			break;
    case '1':             // stub for new screen
      printf("New screen\n");
			break;
		case 'p':
			paused = !paused;
			break;
			break;
		default:
			break;
	}
}
/***************************************************************************/

int main (int argc, char *argv[])
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the escape key.						  */
	srand( time(NULL) );
	glutInit            ( &argc, argv );
       	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize  ( WIDTH,HEIGHT );
	glutCreateWindow    ( "Computer Graphics" );
	glutDisplayFunc     ( display );
	glutIdleFunc	    ( display );
	glutMouseFunc       ( mouse );
	glutKeyboardFunc    ( keyboard );

        init_window();				             //create_window


	glutMainLoop        ( );                 // Initialize The Main Loop
}
