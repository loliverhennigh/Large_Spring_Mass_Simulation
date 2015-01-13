
#include "lsms.h"

#include <stdio.h>

int main()
{
	lsms * l = lsms_create(2,2);
	printf("test \n");
	lsms_set_particle(l, 0, 0.0, 0.0, 0.0, 0.0, 0.0);
	lsms_set_particle(l, 1, 1.0, 1.0, 0.0, 0.0, 0.0);
	float distance = particle_distance_b(l->p[0], l->p[1]);
	printf("test %f \n", distance);
		

}


