
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

float particle_get_x_a(particle * p) { return p->x_a; }
float particle_get_y_a(particle * p) { return p->y_a; }
float particle_get_z_a(particle * p) { return p->z_a; }
float particle_get_x_b(particle * p) { return p->x_b; }
float particle_get_y_b(particle * p) { return p->y_b; }
float particle_get_z_b(particle * p) { return p->z_b; }

void particle_add_force(particle * p, force * f)
{
	p->x_force = p->x_force + f->x;
	p->y_force = p->y_force + f->y;
	p->z_force = p->z_force + f->z;
}

float particle_distance_a(particle * p_a, particle * p_b)
{
	float distance;
	distance = pow((p_a->x_a - p_b->x_a), 2);
	distance = distance + pow((p_a->y_a - p_b->y_a), 2);
	distance = distance + pow((p_a->z_a - p_b->z_a), 2);
	distance = sqrt(distance);
	return distance;
}

float particle_distance_b(particle * p_a, particle * p_b)
{
	float distance;
	distance = pow((p_a->x_b - p_b->x_b), 2);
	distance = distance + pow((p_a->y_b - p_b->y_b), 2);
	distance = distance + pow((p_a->z_b - p_b->z_b), 2);
	distance = sqrt(distance);
	return distance;
}

float particle_distance_squared_a(particle * p_a, particle * p_b)
{
	float distance;
	distance = pow((p_a->x_a - p_b->x_a), 2);
	distance = distance + pow((p_a->y_a - p_b->y_a), 2);
	distance = distance + pow((p_a->z_a - p_b->z_a), 2);
	return distance;
}

float particle_distance_squared_b(particle * p_a, particle * p_b)
{
	float distance;
	distance = pow((p_a->x_b - p_b->x_b), 2);
	distance = distance + pow((p_a->y_b - p_b->y_b), 2);
	distance = distance + pow((p_a->z_b - p_b->z_b), 2);
	return distance;
}

void particle_calc_charge_force(particle * p_a, particle * p_b, force * force_store_space)
{
	float distance = 0.0;
	distance = particle_distance_a(p_a, p_b);
	distance = (.1 * p_a->charge * p_b->charge) / pow(distance,3); // need to change charge constant
	force_init(force_store_space, (p_a->x_a - p_b->x_a) * distance, (p_a->y_a - p_b->y_a) * distance, (p_a->z_a - p_b->z_a) * distance);
	particle_add_force(p_a, force_store_space);
	force_invert(force_store_space);
	particle_add_force(p_b, force_store_space);	
}




