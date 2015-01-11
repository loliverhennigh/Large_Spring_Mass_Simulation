

#ifndef _point_H_
#define _point_H_


typedef struct {
	float x_a;
	float x_b;
	float x_force;
	float y_a;
	float y_b;
	float y_force;
	float z_a;
	float z_b;
	float z_force;
	float mass;
	float charge;
	spring ** connections;

} particle;

void particle_init(particle * p, float x, float y, float z, float mass, float charge, spring ** connections);

#endif	



