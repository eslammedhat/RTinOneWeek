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
inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.m_vec[0] << ' ' << v.m_vec[1] << ' ' << v.m_vec[2];
}
//----------------------------------------------------------------
inline Vec3 operator+(const Vec3& u, const Vec3& v) {
    return Vec3(u.m_vec[0] + v.m_vec[0], u.m_vec[1] + v.m_vec[1], u.m_vec[2] + v.m_vec[2]);
}
//----------------------------------------------------------------
inline Vec3 operator-(const Vec3& u, const Vec3& v) {
    return Vec3(u.m_vec[0] - v.m_vec[0], u.m_vec[1] - v.m_vec[1], u.m_vec[2] - v.m_vec[2]);
}
//----------------------------------------------------------------
inline Vec3 operator*(const Vec3& u, const Vec3& v) {
    return Vec3(u.m_vec[0] * v.m_vec[0], u.m_vec[1] * v.m_vec[1], u.m_vec[2] * v.m_vec[2]);
}
//----------------------------------------------------------------
inline Vec3 operator*(double t, const Vec3& v) {
    return Vec3(t * v.m_vec[0], t * v.m_vec[1], t * v.m_vec[2]);
}
//----------------------------------------------------------------
inline Vec3 operator*(const Vec3& v, double t) {
    return t * v;
}
//----------------------------------------------------------------
inline Vec3 operator/(Vec3 v, double t) {
    return (1 / t) * v;
}
//----------------------------------------------------------------
inline double dot(const Vec3& u, const Vec3& v) {
    return u.m_vec[0] * v.m_vec[0]
        + u.m_vec[1] * v.m_vec[1]
        + u.m_vec[2] * v.m_vec[2];
}
//----------------------------------------------------------------
inline Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.m_vec[1] * v.m_vec[2] - u.m_vec[2] * v.m_vec[1],
        u.m_vec[2] * v.m_vec[0] - u.m_vec[0] * v.m_vec[2],
        u.m_vec[0] * v.m_vec[1] - u.m_vec[1] * v.m_vec[0]);
}
//----------------------------------------------------------------
inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}


// Type aliases for vec3
using Point3 = Vec3;   // 3D point

#endif // VEC3_H_
