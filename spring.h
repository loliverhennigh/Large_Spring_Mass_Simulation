
#include "particle.h"

#ifndef _spring_H_
#define _spring_H_


typedef struct {
	int type;
	float k;
	particle * a;
	particle * b;

} spring;

void spring_init(spring * s, int type, float k, particle * a, particle *b);

#endif	



