
#include "lsms.h"
#include <malloc.h>

lsms * lsms_create(int num_particles, int num_springs)
{
	int i = 0;
	lsms * l = (lsms *)malloc(sizeof(lsms));
	l->p = (particle **)malloc(sizeof(particle *) * num_particles);
	l->s = (spring **)malloc(sizeof(spring *) * num_springs);
	for(i = 0; i < num_particles; i ++)
	{
		l->p[i] = (particle *)malloc(sizeof(particle));
	}
	for(i = 0; i < num_springs; i++)
	{
		l->s[i] = (spring *)malloc(sizeof(spring));
	}
	l->num_particles = num_particles;
	l->num_springs = num_springs;
}

void lsms_set_particle(lsms * l, int pos, float x, float y, float z, float mass, float charge)
{
	particle_init(l->p[pos], x, y, z, mass, charge);
}

void lsms_set_spring(lsms * l, int pos, int type, float k, particle * a, particle * b)
{
	spring_init(l->s[pos], type, k, a, b);
}
