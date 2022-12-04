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
		v1.Add(v2);
		Vector3 v3 = { 1, 2, 3 };
		return v1 == Vector3{4, 4, 4};
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
		v3.Substract(v1);
		return v1 - v2 == result && v3 == result;
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
		v2.Multiply(2);
		Vector3 v3 = { 1, 2, 3 };
		v3 *= s;
		Vector3 result = Vector3{ 2, 4, 6 };
		return v1 * s == result && s * v1 == result && v2 == result && v3 == result;
	});
	// 7: divide
	AddTest([]()->bool {
		Vector3 v1 = { 2, 4, 6 };
		float s = 2;
		Vector3 v2 = { 2, 4, 6 };
		Vector3 v3 = { 2, 4, 6 };
		v3 /= s;
		Vector3 result = Vector3{ 1, 2, 3 };
		bool b1 = (v1 / s == result);
		bool b2 = (s / v1 == Vector3{ 1.0f, 0.5f, 1.0f / 3.0f });
		v2.Divide(2);
		bool b3 = (v2 == result);
		bool b4 = (v3 == result);
		return b1 && b2 && b3 && b4;
		});

	std::cout << sizeof(Vector3) << std::endl;
	std::cout << Vector3(1, 2, 3) << std::endl;
}
