#ifndef RAY_H_
#define RAY_H_

#include "Vec3.hpp"

class Ray {
public:

	Ray() = default;
	Ray(const Point3& origin, const Vec3& direction);

	Vec3 direction() const;
	Point3 origin() const;

	Point3 at(double t) const;

public:

	Point3 m_origin;
	Vec3 m_direction;

};


#endif // RAY_H_