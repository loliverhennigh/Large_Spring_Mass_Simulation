

#ifndef _point_H_
#define _point_H_


typedef struct {
	float x;
	float y;
	float z;

} force;

force * force_create();
void force_init(force * f, float x, float y, float z);
void force_invert(force * f);
void force_destroy(force * f);

#endif	



