#include "TestVector3.h"
#include "Vector3.h"

using m3::Vector3;

void TestVector3::AddTests()
{
	// 0: equality
	AddTest([]()->bool {
		Vector3 v1 = {1, 2, 3};
		Vector3 v2 = {1, 2, 3};
		return v1 == v2 && v1 == Vector3{1, 2, 3} &&
				Vector3{1, 2, 3} == v1;
	});
	
	// 1: +
	AddTest([]()->bool {
		Vector3 v1 = {1, 2, 3};
		Vector3 v2 = {3, 2, 1};
		//return v1 + v2 == Vector3{ 4, 4, 4 } && (Vector3{ 3, 2, 1 } + v1 == Vector3{ 4, 4, 4 });
		return v1 + v2 == Vector3{ 4, 4, 4 };
	});
	
	// 2: Add && Add_
	AddTest([]()->bool {
		Vector3 v1 = {1, 2, 3};
		Vector3 v2 = {3, 2, 1};
		v1.Add_(v2);
		Vector3 v3 = { 1, 2, 3 };
		return v1 == Vector3{4, 4, 4} && v3.Add(v2) == Vector3{ 4, 4, 4 };
	});
	
	// 3: +=
	AddTest([]()->bool {
		Vector3 v1 = {1, 2, 3};
		Vector3 v2 = {-1, -2, -3};
		v1 += v2;
		return v1 == Vector3{0, 0, 0};
	});

	// 4: - && Substract && Substract_
	AddTest([]()->bool {
		Vector3 v1 = { 1, 2, 3 };
		Vector3 v2 = { 1, 2, 3 };
		Vector3 v3 = { 1, 2, 3 };
		Vector3 result = Vector3{ 0, 0, 0 };
		v3.Substract_(v1);
		return v1 - v2 == result && v3 == result && Vector3{ 1, 2, 3 }.Substract(v1) == result;
	});
	// 5: -=
	AddTest([]()->bool {
		Vector3 v1 = { 1, 2, 3 };
		Vector3 v2 = { 1, 2, 3 };
		v1 -= v2;
		return v1 == Vector3{ 0, 0, 0 };
	});
	// 6: * && Multiply && Multiply_ && *= for s
	AddTest([]()->bool {
		Vector3 v1 = { 1, 2, 3 };
		float s = 2;
		Vector3 v2 = { 1, 2, 3 };
		v2.Multiply_(2);
		Vector3 v3 = { 1, 2, 3 };
		v3 *= s;
		Vector3 result = Vector3{ 2, 4, 6 };
		// TODO s * Vector3
		return v1 * s == result && v1.Multiply(2) == result && v2 == result && v3 == result;
	});
}
