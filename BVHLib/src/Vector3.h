#pragma once

namespace m3
{
#define VECTOR3_EPSILON 0.000001f
struct Vector3
{
    union
    {
        struct {
            float x;
            float y;
            float z;
        };
        float v[3];
    };
    inline Vector3() : x(0.0), y(0.0), z(0.0) {};
    inline Vector3(float scalar) : x(scalar), y(scalar), z(scalar) {}
    inline Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    bool operator==(const Vector3& v);
    Vector3 operator+(const Vector3& v);
    void Add_(const Vector3& v);
    Vector3 operator+=(const Vector3& v);
};

}
