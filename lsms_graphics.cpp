//
// File:        lsms_graphics.cpp
// Author:      Oliver Hennigh
//
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include "lsms.h"
#include "spring.h"
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// open gl stuff
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib,"glut32.lib")      

// my stuff



using namespace std;



double scale = 10;
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();
string double_to_string(double number);
 
// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0; 
double rotate_x=0;
double xtranslate = 0;
double ytranslate = 0;
double ztranslate = 0;

int width = 200;
int height = 400;

int lastX = 150;
int lastY = 150;

double scale_change = .5;

bool in_full_screen = 0;

// time steps -----------------------------------------------
double dt = .001;
double time_elapsed = 0.0;
int direction = 1;
//  ---------------------------------------------------------

string file_name;

void drawStrokeText(char*string,int x,int y,int z);

void drawText(const char * message, double x, double y, double z);

string heat = "temp ";
string timey = "time = 0";
const char *mess = timey.c_str();
const char *temp = heat.c_str();

lsms * l;

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){
 //  Clear screen and Z-buffer
 
  // Reset transformations
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1,1,1);
  drawText(mess,-.9,-.9,-1);
  glLoadIdentity();    
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  // Movement
  glTranslatef(xtranslate,ytranslate,ztranslate);
  // Scale stuff
  glScalef(scale_change,scale_change,scale_change);
  
  glPointSize(3.0);


  //Multi-colored side - FRONT
  glPushMatrix();

 // draw the conections (red is real) (imag is blue -> green)
  for (int i = 0; i < l->num_springs; i++)
  { 
  		glBegin(GL_LINES);
  		glColor3f(1.0,0.0,0.0);
  		glVertex3d(spring_pos_x_a(l->s[i]),spring_pos_y_a(l->s[i]),spring_pos_z_a(l->s[i]));
  		glColor3f(1.0,0.0,0.0);
  		glVertex3d(spring_pos_x_b(l->s[i]),spring_pos_y_b(l->s[i]),spring_pos_z_b(l->s[i]));
  		glEnd();
  }
/*
 // draw the nodes (and heats for them)
   for (int i = 0; i < test.size; i++)
   {
  	glPushMatrix();
		glTranslatef(test.x[i],test.y[i],test.z[i]);
		glScalef(.05,.05,.05);
		glColor3f(1,1,1);
		drawText(double_to_string(gsl_vector_get(test.current_abs, i)).c_str(),test.x[i]+.3,test.y[i]+.1,test.z[i]+.1);
  		glColor3f(gsl_vector_get(test.current_abs, i),0.2,0.2);
  		glutWireTeapot(1);
  	glPopMatrix();
   }
*/
  glFlush();
  glutSwapBuffers();
 
}


void drawText(const char * message, double x, double y, double z)
{
	/* raster pos sets the current raster position
	 * mapped via the modelview and projection matrices
	 */
	glRasterPos3d((GLdouble)x, (GLdouble)y, (GLdouble)z);
	glColor3f(1,1,1);

	// write using bitmap

	while (*message) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *message++);
	}
}

 


// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

void timeMaker(unsigned char key, int x, int y)
{
	// change time stuff
	if (key ==  't')
	{
		lsms_update_step(l,dt);
	}
	if (key == 'f')
	{
		lsms_update(l,dt, 10);
	}
	if (key == 'g')
	{
		lsms_update(l,dt, 100);
	}
	if (key == '-')
	{
		direction = direction*(-1);
	}
	
	// move around

	if(key == 'w') 
	{
		ztranslate += 0.02*cos(rotate_y*M_PI/180);
		xtranslate -= 0.02*sin(rotate_y*M_PI/180);	
	}
	if(key == 's')
	{
		ztranslate -= 0.02*cos(rotate_y*M_PI/180);
		xtranslate += 0.02*sin(rotate_y*M_PI/180);
	}
	if(key == 'a')
	{
		xtranslate += 0.02*cos(rotate_y*M_PI/180);
		ztranslate += 0.02*sin(rotate_y*M_PI/180);	
	}
	if(key == 'd')
	{
		xtranslate -= 0.02*cos(rotate_y*M_PI/180);
		ztranslate -= 0.02*sin(rotate_y*M_PI/180);
	}

	// rotate!

	if (rotate_y > 360) rotate_y -= 360;
	else if (rotate_y < -360) rotate_y += 360;

	if(key == 'e')
	{
		scale_change += .001;
	}
	if(key == 'r')
	{
		scale_change -= .001;
	}

	glutPostRedisplay();

	// FULL SCREEN!

	if(key == '1')
	{
		glutFullScreen();
		in_full_screen = 1;
	}
	if(key == '2')
	{
		glutPositionWindow(0,0);
		in_full_screen = 0;
	}
	
	// Print dis (not working yet)	

	if(key == 'p')
	{
		string p = file_name; 
		p.append("_");
		string str = double_to_string(time_elapsed);
		p.append(str);
		p.append(".txt");
		timey.append("   printed to ");
		timey.append(p);
		mess = timey.c_str();
	}

  glFlush();

}


string double_to_string(double number)
{
	ostringstream s;
	s << number;
	return s.str(); 
}


 


void drawStrokeText(char*string,int x,int y,int z)
{
          char *c; 
          glPushMatrix();
          glTranslatef(x, y,z);
          glScalef(0.09f,-0.08f,z);
  
          for (c=string; *c != '\0'; c++)
          {   
                glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
          }   
          glPopMatrix();
}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Prompt function
/*
 	l = lsms_create(6,11);
	lsms_set_particle(l, 0, 0.0, 0.0, 0.0, 1.0, 1.0);
	lsms_set_particle(l, 1, 1.0, 1.0, 0.0, 1.0, 1.0);
	lsms_set_particle(l, 2, 1.0, -1.0, 0.0, 1.0, 1.0);
	lsms_set_particle(l, 3, -1.0, -1.0, 0.0, 1.0, 1.0);
	lsms_set_particle(l, 4, -1.0, -1.0, 1.0, 1.0, 1.0);
	lsms_set_particle(l, 5, -1.5, -1.5, 1.0, 1.0, 1.0);
	lsms_set_spring(l, 0, 1, 1.0, 1.0, 1.0, 0, 1);
	lsms_set_spring(l, 1, 1, 1.0, 1.0, 1.0, 0, 2);
	lsms_set_spring(l, 2, 1, 1.0, 1.0, 1.0, 0, 3);
	lsms_set_spring(l, 3, 1, 1.0, 1.0, 1.0, 1, 2);
	lsms_set_spring(l, 4, 1, 1.0, 1.0, 1.0, 1, 3);
	lsms_set_spring(l, 5, 1, 1.0, 1.0, 1.0, 2, 3);
	lsms_set_spring(l, 6, 1, 1.0, 1.0, 1.0, 1, 4);
	lsms_set_spring(l, 7, 1, 1.0, 1.0, 1.0, 1, 5);
	lsms_set_spring(l, 8, 1, 1.0, 1.0, 1.0, 2, 5);
	lsms_set_spring(l, 9, 1, 1.0, 1.0, 1.0, 3, 5);
	lsms_first_step(l, dt); 
*/
	l = lsms_init_rope(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, .2, 20);
	lsms_set_spring(l, 1, 1, 100.0, 0.0, 0.0, 5, 19);
	lsms_set_particle(l, 5, -1.5, -1.5, 1.0, 1.0, 1.0);
/*	
	l = lsms_create(2,1);
	lsms_set_particle(l, 0, 0.0, 0.0, 0.0, 2.0, 0.0);
	lsms_set_particle(l, 1, 1.0, 1.0, 0.0, 2.0, 0.0);
	lsms_set_spring(l, 0, 1, 2.0, 4.0, 0.0, 0, 1);
*/

  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
  glutCreateWindow("lsms");

  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  glutSetCursor(GLUT_CURSOR_CROSSHAIR);
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(timeMaker);
  // glutMotionFunc(mouse_movements); 

  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
