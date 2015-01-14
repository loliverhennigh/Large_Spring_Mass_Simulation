
#include "lsms.h"

#include <stdio.h>

int main()
{
	lsms * l = lsms_create(2,1);
	printf("test \n");
	lsms_set_particle(l, 0, 0.0, 0.0, 0.0, 1.0, 0.0);
	lsms_set_particle(l, 1, 1.0, 1.0, 0.0, 1.0, 0.0);
	lsms_set_spring(l, 0, 1, 1.0, 1.0, 0, 1);
	lsms_first_step(l, 0.01);
	lsms_update_step(l, 0.1);
	
	printf("test %f \n", l->p[0]->x_a);
	printf("test %f \n", l->p[0]->y_a);
}


