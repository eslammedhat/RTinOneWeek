#include "Vec3.hpp"


//----------------------------------------------------------------
Vec3::Vec3() : m_vec{ 0, 0, 0 } {
};
//----------------------------------------------------------------
Vec3::Vec3 (double x, double y, double z) 
	: m_vec{x, y, z} {
}
//----------------------------------------------------------------
double Vec3::x() const { return m_vec[0]; };
//----------------------------------------------------------------
double Vec3::y() const { return m_vec[1]; };
//----------------------------------------------------------------
double Vec3::z() const { return m_vec[2]; };
//----------------------------------------------------------------
Vec3 Vec3::operator-() const {
	return Vec3(-m_vec[0], -m_vec[1], -m_vec[2]);
}
//----------------------------------------------------------------
double Vec3::operator[](int i) const {
	return m_vec[i];
}
//----------------------------------------------------------------
double& Vec3::operator[](int i) {
	return m_vec[i];
}
//----------------------------------------------------------------
Vec3& Vec3::operator+=(const Vec3& v) {
    m_vec[0] += v.m_vec[0];
    m_vec[1] += v.m_vec[1];
    m_vec[2] += v.m_vec[2];
    return *this;
}
//----------------------------------------------------------------
Vec3& Vec3::operator*=(const double t) {
    m_vec[0] *= t;
    m_vec[1] *= t;
    m_vec[2] *= t;
    return *this;
}
//----------------------------------------------------------------
Vec3& Vec3::operator/=(const double t) {
    return *this *= 1 / t;
}
//----------------------------------------------------------------
double Vec3::length() const {
    return sqrt(length_squared());
}
//----------------------------------------------------------------
double Vec3::length_squared() const {
    return m_vec[0] * m_vec[0] + m_vec[1] * m_vec[1] + m_vec[2] * m_vec[2];
}


// util functions
//----------------------------------------------------------------
namespace vec3 {

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

}