#include <gtest/gtest.h>
#include "solvers/Segment3DSolver.h"
#include "utils/Constants.h"

TEST(Segment3DSolverTests, IntersectionTest) {
    const Segment3D s1({-1, 0, 0}, {1, 0, 0});
    const Segment3D s2({0, -1, 0}, {0, 1, 0});

    const auto result = Segment3DSolver::get_intersect_vector(s1, s2);
    ASSERT_TRUE(result.has_value());
    EXPECT_NEAR(result->x(), 0, constants::EPSILON);
}

TEST(SegmentSolverTest, NoIntersectionTest) {
    const Segment3D s1({10, 0, 0}, {20, 0, 0});
    const Segment3D s2({0, -1, 0}, {0, 1, 0});

    const auto result = Segment3DSolver::get_intersect_vector(s1, s2);
    EXPECT_FALSE(result.has_value());
}