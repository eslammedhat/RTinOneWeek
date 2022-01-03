#include "Ray.hpp"


Ray::Ray(const Point3& orig, const Vec3& dir)
	//: m_origin(orig), m_direction(dir)
{
	m_origin = orig;
	m_direction = dir;
}
//----------------------------------------------------------------
Vec3 Ray::direction() const {
	return m_direction;
}
//----------------------------------------------------------------
Point3 Ray::origin() const {
	return m_origin;
}
//----------------------------------------------------------------
Point3 Ray::at(double t) const {
	return m_origin + m_direction * t;
}