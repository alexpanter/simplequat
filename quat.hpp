#pragma once

#include <cmath>
#include <iostream>
#include <type_traits>

template<typename T>
struct vec
{
    static_assert(std::is_floating_point_v<T>);

    vec() : x(0.0), y(0.0), z(0.0) {}
    vec(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

    T x, y, z;
};

template<typename T>
T dot(const vec<T>& v1, const vec<T>& v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

template<typename T>
vec<T> cross(const vec<T>& v1, const vec<T>& v2)
{
    return {v1.y*v2.z - v2.y*v1.z, v2.x*v1.z - v1.x*v2.z, v1.x*v2.y - v2.x*v1.y};
}

template<typename T>
vec<T> operator* (T s, const vec<T>& v)
{
    return vec<T>{s*v.x, s*v.y, s*v.z};
}

template <typename T>
vec<T> operator+(const vec<T>& v1, const vec<T>& v2)
{
    return vec<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template <typename T>
vec<T> operator-(const vec<T>& v)
{
	return {-v.x, -v.y, -v.z};
}



template<typename T>
struct quat
{
    static_assert(std::is_floating_point_v<T>);

    quat() : w(0.0), x(0.0), y(0.0), z(0.0) {}
    quat(T _w, T _x, T _y, T _z) : w(_w), x(_x), y(_y), z(_z) {}
    quat(T _w, const vec<T>& v) : w(_w), x(v.x), y(v.y), z(v.z) {}

    vec<T> xyz() const { return {x, y, z}; }

    T w, x, y, z;
};

template<typename T>
std::ostream& operator<<(std::ostream& s, const quat<T>& q)
{
    return s << '{' << q.w << ", " << q.x << "i, " << q.y << "j, " << q.z << "k}";
}

template<typename T>
quat<T> operator+ (const quat<T>& q1, const quat<T>& q2)
{
    return {q1.w+q2.w, q1.x+q2.x, q1.y+q2.y, q1.z+q2.z};
}

template<typename T>
quat<T> operator- (const quat<T>& q1, const quat<T>& q2)
{
    return {q1.w-q2.w, q1.x-q2.x, q1.y-q2.y, q1.z-q2.z};
}

template<typename T>
quat<T> operator* (const quat<T>& q1, const quat<T>& q2)
{
    T w = q1.w*q2.w - dot(q1.xyz(), q2.xyz());
    vec<T> v = q1.w*q2.xyz() + q2.w*q1.xyz() + cross(q1.xyz(), q2.xyz());

    return quat<T>{w, v};
}

template<typename T>
quat<T> operator* (T s, const quat<T> q)
{
	return quat<T>(s*q.w, s*q.xyz());
}

template<typename T>
quat<T> operator- (const quat<T>& q)
{
	return {-q.w, -q.x, -q.y, -q.z};
}

template<typename T>
T magnitude(const quat<T> q)
{
	return std::sqrt(q.w*q.w + dot(q.xyz(), q.xyz()));
}

template<typename T>
quat<T> conjugate(const quat<T> q)
{
	return quat<T>(q.w, -q.xyz());
}

template<typename T>
quat<T> inverse(const quat<T> q)
{
	T mag = magnitude(q);
	return (T{1.0} / (mag*mag)) * conjugate(q);
}
