/* David Oguns
 * Computer Graphics II
 * Ray Tracer
 * March 31, 2008
 * raytrace.h
 *
 * This file contains the prototypes for functions defined in raytrace.c
 * that will be called from outside of the source file itself.
 */

#ifndef _RAYTRACE_H_
#define _RAYTRACE_H_

#include <libspe2.h>
#include "../spu/spe_program_info.h"
#include "scene.h"
#include "ray.h"

#define MAX_SPES		6

typedef struct
{
	/* context spe should execute in */
	spe_context_ptr_t	spe_context;
	/* information on how spe exeuction terminated */
	spe_stop_info_t		spe_stop;
	spe_program_info_t	program_info;
} spe_pthread_info_t;


/* called to start the ray tracing process */
void raytrace(unsigned int *buffer, scene_t *scene,
		float fovY, float aspectRatio, float nearZ, float farZ,
		unsigned int width,	unsigned int height, 
		unsigned int samplesPerPixelSq, unsigned int depth,
		unsigned int numSpes);

#endif

