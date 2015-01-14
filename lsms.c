
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
	return l;
}

void lsms_set_particle(lsms * l, int pos, float x, float y, float z, float mass, float charge)
{
	particle_init(l->p[pos], x, y, z, mass, charge);
}

void lsms_set_spring(lsms * l, int pos, int type, float k, float x_0, int pos_a, int pos_b)
{
	spring_init(l->s[pos], type, k, x_0, l->p[pos_a], l->p[pos_b]);
}

void lsms_force_from_springs(lsms * l)
{
	int i = 0;
	force * f = force_create();
	for(i = 0; i < l->num_springs; i++)
	{
		spring_calc_force(l->s[i], f);
	}
	force_destroy(f);
}

void lsms_force_from_charges(lsms * l)
{
	int i = 0;
	int j = 0;
	force * f = force_create();
	for(i = 0; i < l->num_particles; i++)
	{
		for(j = i+1; j < l->num_particles; j++)
		{
			particle_calc_charge_force(l->p[i], l->p[j], f);
		}

	}
	force_destroy(f);
}

void lsms_first_step(lsms * l, float dt)
{
	int i = 0;
	lsms_force_zero(l);
	lsms_force_from_springs(l);
	lsms_force_from_charges(l);
	for (i = 0; i < l->num_particles; i++)
	{
		particle_first_step(l->p[i], dt);
	}
}

void lsms_update_step(lsms * l, float dt)
{
	lsms_force_zero(l);
	lsms_force_from_springs(l);
	lsms_force_from_charges(l);
}

void lsms_force_zero(lsms * l)
{
	int i = 0;
	for(i = 0; i < l->num_particles; i++)
	{
		particle_force_zero(l->p[i]);
	}
}













