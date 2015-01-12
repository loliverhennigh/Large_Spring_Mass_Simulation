
#include "spring.h"


void spring_init(spring * s, int type, float k, particle * a, particle *b)
{
	s->type = type;
	s->k = k;
	s->a = a;
	s->b = b;
}


