#ifndef VEC3_H_
#define VEC3_H_

#include <cmath>
#include <iostream>

using std::sqrt;

// class diffs
//----------------------------------------------------------------
class Vec3 {
public:

    Vec3();
    Vec3(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Vec3 operator-() const;

    double operator[](int i) const;
    double& operator[](int i);

    Vec3& operator+=(const Vec3& v);

    Vec3& operator*=(const double t);

    Vec3& operator/=(const double t);

    double length() const;

    double length_squared() const;

public:
    double m_vec[3];
};


// util functions
//----------------------------------------------------------------
namespace vec3 {

    inline std::ostream& operator<<(std::ostream& out, const Vec3& v);

    inline Vec3 operator+(const Vec3& u, const Vec3& v);

    inline Vec3 operator-(const Vec3& u, const Vec3& v);

    inline Vec3 operator*(const Vec3& u, const Vec3& v);

    inline Vec3 operator*(double t, const Vec3& v);

    inline Vec3 operator*(const Vec3& v, double t);

    inline Vec3 operator/(Vec3 v, double t);

    inline double dot(const Vec3& u, const Vec3& v);

    inline Vec3 cross(const Vec3& u, const Vec3& v);

    inline Vec3 unit_vector(Vec3 v);

}


// Type aliases for vec3
using Point3 = Vec3;   // 3D point

#endif // VEC3_H_
