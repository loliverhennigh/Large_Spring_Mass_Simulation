
#include "spring.h"
#include "force.h"

void spring_init(spring * s, int type, float k, float x_0, particle * a, particle *b)
{
	s->type = type;
	s->k = k;
	s->x_0 = x_0;
	s->a = a;
	s->b = b;
}

int spring_get_type(spring * s) { return s->type; }

void spring_calc_force(spring * s, force * force_store_space)
{
	float distance = 0.0;
	distance = particle_distance_a(s->a, s->b);
	distance = ((distance - s->x_0) * s->k) / distance;
	force_init(force_store_space, (particle_get_x_a(s->a) - particle_get_x_a(s->b)) * distance, (particle_get_y_a(s->a) - particle_get_y_a(s->b)) * distance, (particle_get_z_a(s->a) - particle_get_z_a(s->b)) * distance);
	particle_add_force(s->a, force_store_space);
	force_invert(force_store_space);
	particle_add_force(s->b, force_store_space);	
}

