
#include "particle.h"
#include "force.h"
#include<malloc.h>


void particle_init(particle * p, float x, float y, float z, float mass, float charge)
{
	// init things
	p->x_a = x;
	p->x_b = x;
	p->x_force = 0.0;
	p->y_a = y;
	p->y_b = y;
	p->y_force = 0.0;
	p->z_a = z;
	p->z_b = z;
	p->z_force = 0.0;
	p->mass = mass;
	p->charge = charge;
}

void particle_add_force(particle * p, force * f)
{
	p->x_force = p->x_force + f->x;
	p->y_force = p->y_force + f->y;
	p->z_force = p->z_force + f->z;
}

