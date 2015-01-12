
#include "lsms.h"
#include <malloc.h>

lsms * lsms_create(int num_particles, int num_springs)
{
	int i = 0;
	lsms * l = (lsms *)malloc(sizeof(lsms));
	lsms->p = (particle **)malloc(sizeof(particle *) * num_particles);
	lsms->s = (spring **)malloc(sizeof(spring *) * num_springs);
	for(i = 0; i < num_particles; i ++)
	{
		lsms->p[i] = (particle *)malloc(sizeof(particle));
	}
	for(i = 0; i < num_springs; i++)
	{
		lsms->s[i] = (spring *)malloc(sizeof(spring));
	}
	lsms->num_particles = num_particles;
	lsms->num_springs = num_springs;
}


