#include "ray.h"
#include "material.h"
#include "light.h"
#include <iostream>

// Apply the phong model to this point on the surface of the object, returning
// the color of that point.
vec3f Material::shade( Scene *scene, const ray& r, const isect& i ) const
{
	// YOUR CODE HERE

	// For now, this method just returns the diffuse color of the object.
	// This gives a single matte color for every distinct surface in the
	// scene, and that's it.  Simple, but enough to get you started.
	// (It's also inconsistent with the phong model...)

	// Your mission is to fill in this method with the rest of the phong
	// shading model, including the contributions of all the light sources.
    // You will need to call both distanceAttenuation() and shadowAttenuation()
    // somewhere in your code in order to compute shadows and light falloff.

	vec3f N = i.N;
	vec3f V = r.getDirection();
	vec3f P = r.at(i.t);
	vec3f pointColor = ke + prod(scene->m_ambient, ka);
	//std::cout << scene->m_ambient[0]*100 << std::endl;
	typedef list<Light*>::const_iterator iter;
	iter j;
	for (j = scene->beginLights(); j != scene->endLights(); ++j)
	{
		
		vec3f L = (*j)->getDirection(P);
		vec3f R = (L - 2 * (N * L) * N).normalize();
		double theta = maximum(0, R * V);
		double specular = pow(theta, shininess * 128);
		pointColor +=
			prod
			(
				prod((*j)->distanceAttenuation(P) * (*j)->shadowAttenuation(P), (*j)->getColor(P)),
				prod
				(
					maximum(0, N * L) * kd,
					vec3f(1, 1, 1) - kt
				)
				+
				specular * ks
			);
		/*
		pointColor += prod(
			(*j)->shadowAttenuation(P),
			prod(
					(*j)->getColor(P),
					(*j)->distanceAttenuation(P) *
					(
						ks * specular + 
						prod(vec3f(1, 1, 1) - kt,kd * maximum(0, N.dot(L)))
					)
				)
		);*/ /*
		pointColor +=
			prod
			(
				(*j)->shadowAttenuation(P) * (*j)->distanceAttenuation(P),
				prod
				(
					maximum(0, N * L) * prod(kd, (*j)->getColor(P)),
					vec3f(1, 1, 1) - kt
				)
				+
				specular * prod(ks, (*j)->getColor(P))
			);*/
		
	}

	return pointColor.clamp();
}
