
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
float particle_get_x_a(particle * p);
float particle_get_y_a(particle * p);
float particle_get_z_a(particle * p);
float particle_get_x_b(particle * p);
float particle_get_y_b(particle * p);
float particle_get_z_b(particle * p);
float particle_get_mass(particle * p);
void particle_set_x_a(particle * p, float x);
void particle_set_x_b(particle * p, float x);
void particle_set_y_a(particle * p, float y);
void particle_set_y_b(particle * p, float y);
void particle_set_z_a(particle * p, float z);
void particle_set_z_b(particle * p, float z);
void particle_swap_a_b(particle *p);
void particle_add_force(particle * p, force * f);
float particle_distance_a(particle * p_a, particle * p_b);
float particle_distance_b(particle * p_a, particle * p_b);
float particle_distance_squared_a(particle * p_a, particle * p_b);
float particle_distance_squared_b(particle * p_a, particle * p_b);
void particle_calc_charge_force(particle * p_a, particle * p_b, force * force_store_space);
void particle_force_zero(particle * p);
void particle_first_step(particle * p, float dt);
void particle_update_step(particle * p, float dt);

#endif	



