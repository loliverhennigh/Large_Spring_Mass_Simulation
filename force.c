
#include "force.h"

force * force_create()
{
	force * f = (force *)malloc(sizeof(force));i
	return f;
}

force_init(force * f, float x, float y, float z)
{
	f->x = x;
	f->y = y;
	f->z = z;
}

force_invert(force * f)
{
	f->x = -x;
	f->y = -y;
	f->z = -z;
}


