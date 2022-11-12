#include "TestVector3.h"
#include "Vector3.h"

using m3::Vector3;

void TestVector3::AddTests()
{
    // 1: equality
    AddTest([]()->bool {
        Vector3 v1 = {1, 2, 3};
        Vector3 v2 = {1, 2, 3};
        return v1 == v2 && v1 == Vector3{1, 2, 3} &&
                Vector3{1, 2, 3} == v1;
    });
    
    // 2: +
    AddTest([]()->bool {
        Vector3 v1 = {1, 2, 3};
        Vector3 v2 = {3, 2, 1};
        return v1 + v2 == Vector3{4, 4, 4} && Vector3{3, 2, 1} + v1 == Vector3{4, 4, 4};
    });
    
    // 3: Add_
    AddTest([]()->bool {
        Vector3 v1 = {1, 2, 3};
        Vector3 v2 = {3, 2, 1};
        v1.Add_(v2);
        return v1 == Vector3{4, 4, 4};
    });
    
    // 4: +=
    AddTest([]()->bool {
        Vector3 v1 = {1, 2, 3};
        Vector3 v2 = {-1, -2, -3};
        v1 += v2;
        return v1 == Vector3{0, 0, 0};
    });
}
