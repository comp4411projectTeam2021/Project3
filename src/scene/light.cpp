#include <cmath>

#include "light.h"

double DirectionalLight::distanceAttenuation( const vec3f& P ) const
{
	// distance to light is infinite, so f(di) goes to 0.  Return 1.
	return 1.0;
}


vec3f DirectionalLight::shadowAttenuation( const vec3f& P ) const
{
    // YOUR CODE HERE:
    // You should implement shadow-handling code here.
	isect i;
	return scene->intersect(ray(P, getDirection(P)), i) ? prod(getColor(P), i.getMaterial().kt) : getColor(P);
}

vec3f DirectionalLight::getColor( const vec3f& P ) const
{
	// Color doesn't depend on P 
	return color;
}

vec3f DirectionalLight::getDirection( const vec3f& P ) const
{
	return -orientation;
}

double PointLight::distanceAttenuation( const vec3f& P ) const
{
	// YOUR CODE HERE

	// You'll need to modify this method to attenuate the intensity 
	// of the light based on the distance between the source and the 
	// point P.  For now, I assume no attenuation and just return 1.0
	
	//double distance = 1.0 / (getScene()->m_attConstant + getScene()->m_attLinear * (position - P).length() + getScene()->m_attQuatric * (position - P).length_squared());
	//return minimum(1.0 / (getScene()->m_attConstant + getScene()->m_attLinear * (position - P).length() + getScene()->m_attQuatric * (position - P).length_squared()), 1.0);
	return minimum(1.0 / (constant_attenuation_coeff + linear_attenuation_coeff * (position - P).length() + quadratic_attenuation_coeff * (position - P).length_squared()),1.0);
}

vec3f PointLight::getColor( const vec3f& P ) const
{
	// Color doesn't depend on P 
	return color;
}

vec3f PointLight::getDirection( const vec3f& P ) const
{
	return (position - P).normalize();
}


vec3f PointLight::shadowAttenuation(const vec3f& P) const
{
    // YOUR CODE HERE:
    // You should implement shadow-handling code here.
	isect i;
	return scene->intersect(ray(P, getDirection(P)), i) ? prod(getColor(P), i.getMaterial().kt) : getColor(P);
}
