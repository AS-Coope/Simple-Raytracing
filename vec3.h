#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

#include <cmath>
#include <iostream>

class vec3{
    public:
        double e[3];

        // constructors with initializer lists
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        // getter functions for each of the 3 dimensions
        double x() const {
            return e[0];
        }
        double y() const {
            return e[1];
        }
        double z() const {
            return e[2];
        }

        vec3 operator-() const {
            return vec3(-e[0], -e[1], -e[2]);
        }

        double operator[](int i) const {
            return e[i];
        } // seems to return a specific dimension based on i (can't this cause an array out of bounds error?)
        // provides a read only view of the dimension selected (via the const keyword)

        double& operator[](int i) {
            return e[i];
        } // seems to return the address of the dimension selected
        // points directly to the dimension in memory (via the & - ref)hence allowing writing to that dimension

        // adding a vector to the current vector
        vec3& operator+=(const vec3& v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // multiplying a scalar by the current vector
        vec3& operator*=(double t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // dividing the vector by a scalar
        vec3& operator/=(double t){
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }
};

// point3 is an alias for vec3
using point3 = vec3;

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v){
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// multiplying a vector by a vector
inline vec3 operator*(const vec3& u, const vec3& v){
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// multiplying a vector by a scalar (mulitplying scalar by each dimension in the vector)
inline vec3 operator*(double t, const vec3& v){
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t){
    return t * v;
}

inline vec3 operator/(const vec3& v, double t){
    return (1/t) * v;
}

inline double dot (const vec3& u, const vec3& v){
    return   u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

inline vec3 cross (const vec3& u, const vec3& v){
    return vec3(
        u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]
    );
}

inline vec3 unit_vector(const vec3& v){
    return v / v.length();
}

#endif // VEC3_H_INCLUDED
