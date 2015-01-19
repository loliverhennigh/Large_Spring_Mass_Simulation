
#include "particle.h"
#include "spring.h"

#ifndef _lsms_H_
#define _lsms_H_


typedef struct {
	int num_particles;
	int num_springs;
	particle ** p;
	spring ** s;
} lsms;

lsms * lsms_create(int num_particles, int num_springs);
void lsms_set_particle(lsms * l, int pos, double x, double y, double z, double mass, double charge);
void lsms_set_spring(lsms * l, int pos, int type, double k, double k_d, double x_0, int pos_a, int pos_b);
void lsms_force_from_springs(lsms * l, double dt);
void lsms_force_from_charges(lsms * l);
void lsms_update_step(lsms * l, double dt);
void lsms_first_step(lsms * l, double dt);
void lsms_force_zero(lsms * l);
void lsms_update(lsms * l, double dt, int steps);
lsms * lsms_init_rope(double start_x, double start_y, double start_z, double end_x, double end_y, double end_z, double mass, double k, double k_d, int x_div);

#endif	



