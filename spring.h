
#include "particle.h"

#ifndef _spring_H_
#define _spring_H_


typedef struct {
	int type;
	float k;
	float x_0;
	particle * a;
	particle * b;

} spring;

void spring_init(spring * s, int type, float k, float x_0, particle * a, particle *b);
int spring_get_type(spring * s);
void spring_calc_force(spring * s);

#endif	



