
#include "lsms.h"
#include <malloc.h>
#include <math.h>

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

void lsms_set_particle(lsms * l, int pos, double x, double y, double z, double mass, double charge)
{
	particle_init(l->p[pos], x, y, z, mass, charge);
}

void lsms_set_spring(lsms * l, int pos, int type, double k, double k_d, double x_0, int pos_a, int pos_b)
{
	spring_init(l->s[pos], type, k, k_d, x_0, l->p[pos_a], l->p[pos_b]);
}

lsms * lsms_init_rope(double start_x, double start_y, double start_z, double end_x, double end_y, double end_z, double mass, double k, double k_d, int x_div)
{
	int i = 0;
	lsms * l = lsms_create(x_div, x_div - 1);
	double dx = (start_x - end_x) / (double)x_div;
	double dy = (start_y - end_y) / (double)x_div;
	double dz = (start_z - end_z) / (double)(x_div);
	double h = pow(dx,2) + pow(dy,2) + pow(dz,2);
	h = pow(h,.5);
	for (i = 0; i < x_div; i++)
	{ 
		lsms_set_particle(l, i, start_x + (double)(i)*dx, start_y + (double)(i)*dy, start_z + (double)(i)*dz, mass, 0.0);
	}
	for (i = 0; i < x_div-1; i++)
	{
		lsms_set_spring(l, i, 1, k, k_d, h, i, i+1);
	}
	return l;
}

void lsms_force_from_springs(lsms * l, double dt)
{
	int i = 0;
	force * f = force_create();
	for(i = 0; i < l->num_springs; i++)
	{
		spring_calc_force(l->s[i], dt, f);
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

void lsms_first_step(lsms * l, double dt)
{
	int i = 0;
	lsms_force_zero(l);
	lsms_force_from_springs(l, dt);
	lsms_force_from_charges(l);
	for (i = 0; i < l->num_particles; i++)
	{
		particle_first_step(l->p[i], dt);
	}
}

void lsms_update_step(lsms * l, double dt)
{
	int i = 0;
	lsms_force_zero(l);
	lsms_force_from_springs(l, dt);
	lsms_force_from_charges(l);
	for (i = 0; i < l->num_particles; i++)
	{
		particle_update_step(l->p[i], dt);
	}
}

void lsms_force_zero(lsms * l)
{
	int i = 0;
	for(i = 0; i < l->num_particles; i++)
	{
		particle_force_zero(l->p[i]);
	}
}

void lsms_update(lsms * l, double dt, int steps)
{
	int i = 0;
	for(i = 0; i < steps; i++)
	{
		lsms_update_step(l, dt);
	}
}











