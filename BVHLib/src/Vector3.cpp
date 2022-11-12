#include "Vector3.h"
#include <cmath>

namespace m3 {
    bool Vector3::operator==(const Vector3& v)
    {
        return std::abs(x - v.x) < VECTOR3_EPSILON && std::abs(x - v.x) < VECTOR3_EPSILON && std::abs(x - v.x) < VECTOR3_EPSILON;
    }

    Vector3 Vector3::operator+(const Vector3& v)
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    void Vector3::Add_(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    Vector3 Vector3::operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
}
