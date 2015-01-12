
#include "particle.h"
#include "force.h"
#include <malloc.h>
#include <math.h>

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

float particle_get_x(particle * p) { return p->x_a; }
float particle_get_y(particle * p) { return p->y_a; }
float particle_get_z(particle * p) { return p->z_a; }

void particle_add_force(particle * p, force * f)
{
	p->x_force = p->x_force + f->x;
	p->y_force = p->y_force + f->y;
	p->z_force = p->z_force + f->z;
}

float particle_distance(particle * p_a, particle * p_b)
{
	float distance;
	distance = pow((p_a->x_a - p_b->x_a), 2);
	distance = distance + pow((p_a->y_a - p_b->y_a), 2);
	distance = distance + pow((p_a->z_a - p_b->z_a), 2);
	distance = sqrt(distance);
	return distance;
}

