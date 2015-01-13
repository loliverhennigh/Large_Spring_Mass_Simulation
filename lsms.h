
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
void lsms_set_particle(lsms * l, int pos, float x, float y, float z, float mass, float charge);
void lsms_set_spring(lsms * l, int pos, int type, float k, float x_0, int pos_a, int pos_b);
void lsms_force_from_springs(lsms * l);
void lsms_force_from_charges(lsms * l);


#endif	



