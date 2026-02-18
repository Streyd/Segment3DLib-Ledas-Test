#include <gtest/gtest.h>
#include "core/Vector3D.h"
#include "utils/Constants.h"

TEST(Vector3DTests, CrossTest) {
    const Vector3D v1(1, 0, 0);
    const Vector3D v2(0, 1, 0);
    const Vector3D n = v1.cross(v2);

    EXPECT_NEAR(n.x(), 0, constants::EPSILON);
    EXPECT_NEAR(n.y(), 0, constants::EPSILON);
    EXPECT_NEAR(n.z(), 1, constants::EPSILON);

    const Vector3D n2 = v2.cross(v1);
    EXPECT_NEAR(n2.z(), -1, constants::EPSILON);
}

TEST(Vector3DTests, DotTest) {
    const Vector3D v1(1, 2, 3);
    const Vector3D v2(4, -5, 6);

    EXPECT_NEAR(v1.dot(v2), 12.0, constants::EPSILON);
}