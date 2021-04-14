#include <cmath>

#include "Square.h"

bool Square::intersectLocal( const ray& r, isect& i ) const
{
	vec3f p = r.getPosition();
	vec3f d = r.getDirection();

	if( d[2] == 0.0 ) {
		return false;
	}

	double t = -p[2]/d[2];

	if( t <= RAY_EPSILON ) {
		return false;
	}

	vec3f P = r.at( t );

	if( P[0] < -0.5 || P[0] > 0.5 ) {	
		return false;
	}

	if( P[1] < -0.5 || P[1] > 0.5 ) {	
		return false;
	}

	i.obj = this;
	i.t = t;
	if( d[2] > 0.0 ) {
		i.N = vec3f( 0.0, 0.0, -1.0 );
	} else {
		i.N = vec3f( 0.0, 0.0, 1.0 );
	}

	return true;
}

bool Square::getObjUV(const ray& r, vec3f& u, vec3f& v) const
{
	//std::cout << "aaa" << std::endl;
	vec3f p = transform->globalToLocalCoords(r.getPosition());
	vec3f d = transform->globalToLocalCoords(r.getDirection() - r.getPosition()) - p;
	d /= d.length();
	ray objRay(p, d);
	isect i;
	if (intersectLocal(objRay, i))
	{
		vec3f P = objRay.at(i.t);
		u = vec3f(P[0] + 0.5, 0, 1).clamp();
		v = vec3f(P[1] + 0.5, 0, 1).clamp();
		return true;
	}
	else return false;
	/*
	ray objRay(p, d);
	double t = -p[2] / d[2];
	if (t <= RAY_EPSILON)return false;

	vec3f P = r.at(t);
	if (P[0] < -0.5 || P[0] > 0.5)return false;
	if (P[1] < -0.5 || P[1] > 0.5)return false;

	u = vec3f(P[0] + 0.5, 0, 1).clamp();
	v = vec3f(P[1] + 0.5, 0, 1).clamp();
	*/
	
}
