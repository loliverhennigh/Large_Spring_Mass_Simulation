
#include "lsms.h"

#include <stdio.h>

int main()
{
	lsms * l;
	lsms * l_b = lsms_init_rope(0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.1, 10.0, 10.0, 10);
	lsms * l_a = lsms_init_rope(0.1, -1.0, 0.0, 0.1, 1.0, 0.0, 0.1, 10.0, 10.0, 10);
	lsms * l_c = lsms_init_rope(0.03333, -1.0, 0.0, 0.033, 1.0, 0.0, 0.1, 10.0, 10.0, 10);
	lsms * l_d = lsms_init_rope(0.0666, -1.0, 0.0, 0.06666, 1.0, 0.0, 0.1, 10.0, 10.0, 10);
	l = lsms_add_tensor(l_b, l_a, 100.0, .0225);
	l = lsms_add_tensor(l, l_c, 100.0, .0225);
	l = lsms_add_tensor(l, l_d, 100.0, .0225);
	lsms_first_step(l, 0.01);
	lsms_update(l, .001, 1000000);
	printf("done \n");
/*	
	printf("test \n");
	lsms_set_particle(l, 0, 0.0, 0.0, 0.0, 1.0, 0.0);
	lsms_set_particle(l, 1, 1.0, 1.0, 0.0, 1.0, 0.0);
	lsms_set_spring(l, 0, 1, 1.0, 1.0, 1.0, 0, 1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
	lsms_update_step(l, 0.1);
*/	
}


