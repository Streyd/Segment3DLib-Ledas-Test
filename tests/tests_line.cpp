#include <gtest/gtest.h>
#include "core/Line3D.h"
#include "solvers/Line3DSolver.h"


TEST(Line3DTests, GetPointTest) {
    const Vector3D p(0, 0, 0);
    const Vector3D k(1, 0, 0);
    const Line3D line(p, k);

    const Vector3D result = line.get_point(2.5);
    EXPECT_DOUBLE_EQ(result.x(), 2.5);
    EXPECT_DOUBLE_EQ(result.y(), 0.0);
}


TEST(Line3DTests, GetParamTest) {
    const Line3D line({0,0,0}, {0,1,0});
    const Vector3D point(0, 5, 0);

    const auto t = line.get_param(point);
    ASSERT_TRUE(t.has_value());
    EXPECT_DOUBLE_EQ(t.value(), 5.0);

    const auto t_false = line.get_param({1, 1, 1});
    EXPECT_FALSE(t_false.has_value());
}

TEST(Line3DSolverTest, Intersection) {
    const Line3D l1({0,0,0}, {1,0,0});
    const Line3D l2({5, -5, 0}, {0, 1, 0});

    const auto result = Line3DSolver::get_intersect_vector(l1, l2);
    ASSERT_TRUE(result.has_value());
    EXPECT_NEAR(result->x(), 5.0, 1e-9);
    EXPECT_NEAR(result->y(), 0.0, 1e-9);
}