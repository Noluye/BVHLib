#pragma once
#include <iostream>

namespace m3
{
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

		bool operator==(const Vector3& v) const;
		bool operator!=(const Vector3& v) const;

		Vector3 operator+(const Vector3& v) const;
		void Add(const Vector3& v);
		Vector3 operator+=(const Vector3& v);

		Vector3 operator-(const Vector3& v) const;
		void Substract(const Vector3& v);
		Vector3 operator-=(const Vector3& v);

		Vector3 operator*(float s) const;
		void Multiply(float s);
		Vector3 operator*=(float s);

		Vector3 operator/(float s) const;
		Vector3 operator/(const Vector3& v) const;
		void Divide(float s);
		void Divide(const Vector3& v);
		Vector3 operator/=(float s);
		Vector3 operator/=(const Vector3& v);

		float Dot(const Vector3& v) const;
		float LenSq() const;
		float Len() const;
		void Normalize();
		Vector3 Normalized() const;
		void Clamp(Vector3 min, Vector3 max);
		Vector3 Clamped(Vector3 min, Vector3 max) const;
		
		Vector3 Project(const Vector3& v) const;
		Vector3 Reject(const Vector3& v) const;
		Vector3 Reflect(const Vector3& v) const;
		Vector3 Cross(const Vector3& v) const;
		
		static float Angle(const Vector3& v1, const Vector3& v2);
		static Vector3 Lerp(const Vector3& start, const Vector3& end, float t);
		static Vector3 Slerp(const Vector3& start, const Vector3& end, float t);
		static Vector3 Nlerp(const Vector3& start, const Vector3& end, float t);
		static Vector3 Min(Vector3 v1, Vector3 v2);
		static Vector3 Max(Vector3 v1, Vector3 v2);
		static Vector3 Rad2Deg(Vector3 rad);
		static Vector3 Deg2Rad(Vector3 deg);

		friend std::ostream& operator<<(std::ostream& output, const Vector3& v);
	};
	// ---------------------------------------------------------------
	Vector3 operator*(float s, const Vector3& v);
	Vector3 operator/(float s, const Vector3& v);
}