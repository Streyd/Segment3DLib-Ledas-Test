#include <gtest/gtest.h>
#include "core/Line3D.h"
#include "solvers/Line3DSolver.h"
#include "utils/Constants.h"


TEST(Line3DSolverTests, CrossingLinesTest) {
    const Line3D l1({0, 0, 0}, {1, 0, 0});
    const Line3D l2({0, 0, 1}, {0, 1, 0});

    const auto result = Line3DSolver::get_crossing_segment(l1, l2);

    EXPECT_FALSE(result.has_value());
    ASSERT_TRUE(result.has_value());
    EXPECT_NEAR(result->get_len(), 1.0, constants::EPSILON);
}

TEST(Line3DSolverTests, SimpleIntersectionTest) {
    const Line3D l1({0, 0, 0}, {1, 0, 0});
    const Line3D l2({5, -5, 0}, {0, 1, 0});

    const auto result = Line3DSolver::get_intersect_vector(l1, l2);

    ASSERT_TRUE(result.has_value());
    EXPECT_NEAR(result->x(), 5.0, constants::EPSILON);
    EXPECT_NEAR(result->y(), 0.0, constants::EPSILON);
    EXPECT_NEAR(result->z(), 0.0, constants::EPSILON);
}

TEST(LineSolverTest, ParallelLines) {
    const Line3D l1({0, 0, 0}, {1, 0, 0});
    const Line3D l2({0, 1, 0}, {1, 0, 0});

    const auto result = Line3DSolver::get_intersect_vector(l1, l2);
    EXPECT_FALSE(result.has_value());
}