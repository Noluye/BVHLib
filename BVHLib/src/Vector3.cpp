#include "Vector3.h"
#include <cmath>

namespace m3 {
	bool Vector3::operator==(const Vector3& v)
	{
		return std::abs(x - v.x) < VECTOR3_EPSILON && std::abs(y - v.y) < VECTOR3_EPSILON && std::abs(z - v.z) < VECTOR3_EPSILON;
	}

	Vector3 Vector3::operator+(const Vector3& v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 Vector3::Add(const Vector3& v)
	{
		return *this + v;
	}

	void Vector3::Add_(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vector3 Vector3::operator+=(const Vector3& v)
	{
		Add_(v);
		return *this;
	}

	Vector3 Vector3::operator-(const Vector3& v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 Vector3::Substract(const Vector3& v)
	{
		return *this - v;
	}

	void Vector3::Substract_(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vector3 Vector3::operator-=(const Vector3& v)
	{
		Substract_(v);
		return *this;
	}

	Vector3 Vector3::operator*(float s)
	{
		return Vector3(x * s, y * s, z * s);
	}

	Vector3 Vector3::Multiply(float s)
	{
		return *this * s;
	}

	void Vector3::Multiply_(float s)
	{
		x *= s;
		y *= s;
		z *= s;
	}

	Vector3 Vector3::operator*=(float s)
	{
		Multiply_(s);
		return *this;
	}
	
}

