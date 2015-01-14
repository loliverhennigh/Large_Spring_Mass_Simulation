
#include "force.h"
#include <malloc.h>

force * force_create()
{
	force * f = (force *)malloc(sizeof(force));
	return f;
}

void force_init(force * f, float x, float y, float z)
{
	f->x = x;
	f->y = y;
	f->z = z;
}

void force_invert(force * f)
{
	f->x = -f->x;
	f->y = -f->y;
	f->z = -f->z;
}

void force_destroy(force * f)
{
	free(f);
	f = NULL;
}

