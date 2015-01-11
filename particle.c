
#include "particle.h"
#include<malloc.h>


void particle_init(particle * p, float x, float y, float z, float mass, float charge, spring ** con)
{
	// init things
	p->x_a = x;
	p->x_b = x;
	p->x_f = 0.0;
	p->y_a = y;
	p->y_b = y;
	p->y_f = 0.0;
	p->z_a = z;
	p->z_b = z;
	p->z_f = 0.0;
	p->mass = mass;
	p->charge = charge;
}

