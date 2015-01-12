

#ifndef _lsms_H_
#define _lsms_H_


typedef struct {
	int num_particles;
	int num_springs;
	particle ** p;
	spring ** s;
} lsms;

lsms * lsms_create(int num_particles, int num_springs);

#endif	



