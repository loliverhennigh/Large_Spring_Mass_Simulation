
#include "force.h"

#ifndef _particle_H_
#define _particle_H_


typedef struct {
	float x_a;
	float x_b;
	float x_force;
	float y_a;
	float y_b;
	float y_force;
	float z_a;
	float z_b;
	float z_force;
	float mass;
	float charge;

} particle;

void particle_init(particle * p, float x, float y, float z, float mass, float charge);
float particle_get_x(particle * p);
float particle_get_y(particle * p);
float particle_get_z(particle * p);
void particle_add_force(particle * p, force * f);
float particle_distance(particle * p_a, particle * p_b);


#endif	



